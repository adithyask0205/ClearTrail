//Insert, Delete, Traverse (in, pre, post) a Binary Search Tree using Array

#include<iostream> // Required for input/output stream operations (cin, cout)
using namespace std;

const int SIZE = 100; // Maximum size of the BST array

// Structure to represent each node in the BST array
struct BSTNode {
    int data;   // Value stored in the node
    bool used;  // Flag to indicate if the node is used
} bstArray[SIZE];

// Initialize the BST with a root value
void maketree(int rootValue) {
    bstArray[0].data = rootValue;
    bstArray[0].used = true;
    // Mark all other nodes as unused
    for (int i = 1; i < SIZE; i++) {
        bstArray[i].used = false;
    }
}

// Set the right child of a node at parentIndex
void setRightChild(int parentIndex, int value) {
    int rightIndex = 2 * parentIndex + 2;
    if (rightIndex >= SIZE) {
        cout << "Array overflow" << endl;
    } else if (bstArray[rightIndex].used) {
        cout << "Invalid insertion" << endl;
    } else {
        bstArray[rightIndex].data = value;
        bstArray[rightIndex].used = true;
    }
}

// Set the left child of a node at parentIndex
void setLeftChild(int parentIndex, int value) {
    int leftIndex = 2 * parentIndex + 1;
    if (leftIndex >= SIZE) {
        cout << "Array overflow" << endl;
    } else if (bstArray[leftIndex].used) {
        cout << "Invalid insertion" << endl;
    } else {
        bstArray[leftIndex].data = value;
        bstArray[leftIndex].used = true;
    }
}

// Inorder traversal: left -> root -> right
void inorderTraversal(int index) {
    // Check if index is within bounds and node is used
    if (index < SIZE && bstArray[index].used) {
        inorderTraversal(2 * index + 1); // Traverse left subtree
        cout << bstArray[index].data << " "; // Visit root
        inorderTraversal(2 * index + 2); // Traverse right subtree
    }
}

// Preorder traversal: root -> left -> right
void preorderTraversal(int index) {
    if (index < SIZE && bstArray[index].used) {
        cout << bstArray[index].data << " "; // Visit root
        preorderTraversal(2 * index + 1); // Traverse left subtree
        preorderTraversal(2 * index + 2); // Traverse right subtree
    }
}

// Postorder traversal: left -> right -> root
void postorderTraversal(int index) {
    if (index < SIZE && bstArray[index].used) {
        postorderTraversal(2 * index + 1); // Traverse left subtree
        postorderTraversal(2 * index + 2); // Traverse right subtree
        cout << bstArray[index].data << " "; // Visit root
    }
}

// Find the index of the inorder successor for deletion
int findInorderSuccessor(int index) {
    int rightChild = 2 * index + 2;
    if (rightChild >= SIZE || !bstArray[rightChild].used) return -1;
    int current = rightChild;
    while (2 * current + 1 < SIZE && bstArray[2 * current + 1].used) {
        current = 2 * current + 1;
    }
    return current;
}

// Delete a node with the given value from the BST
void deleteNode(int value) {
    int index = 0;
    // Search for the node to delete
    while (index < SIZE && bstArray[index].used) {
        if (bstArray[index].data == value) { break; }
        // Go left if value is less, right if greater
        if (value < bstArray[index].data) { index = 2 * index + 1; }
        else { index = 2 * index + 2; }
    }
    // If node with value found
    if (index < SIZE && bstArray[index].used && bstArray[index].data == value) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        bool hasLeft = (leftChild < SIZE && bstArray[leftChild].used);
        bool hasRight = (rightChild < SIZE && bstArray[rightChild].used);
        // Case 1: No children (leaf node)
        if (!hasLeft && !hasRight) {
            bstArray[index].used = false; // Remove node
        }
        // Case 2: Only left child
        else if (hasLeft && !hasRight) {
            // Copy left child's data to current node
            bstArray[index].data = bstArray[leftChild].data;
            bstArray[leftChild].used = false; // Remove left child
            // Move left child's left child up if exists
            if (2 * leftChild + 1 < SIZE && bstArray[2 * leftChild + 1].used) {
                bstArray[2 * index + 1].data = bstArray[2 * leftChild + 1].data;
                bstArray[2 * leftChild + 1].used = false;
            }
            // Move left child's right child up if exists
            if (2 * leftChild + 2 < SIZE && bstArray[2 * leftChild + 2].used) {
                bstArray[2 * index + 2].data = bstArray[2 * leftChild + 2].data;
                bstArray[2 * leftChild + 2].used = false;
            }
        }
        // Case 3: Only right child
        else if (!hasLeft && hasRight) {
            // Copy right child's data to current node
            bstArray[index].data = bstArray[rightChild].data;
            bstArray[rightChild].used = false; // Remove right child
            // Move right child's left child up if exists
            if (2 * rightChild + 1 < SIZE && bstArray[2 * rightChild + 1].used) {
                bstArray[2 * index + 1].data = bstArray[2 * rightChild + 1].data;
                bstArray[2 * rightChild + 1].used = false;
            }
            // Move right child's right child up if exists
            if (2 * rightChild + 2 < SIZE && bstArray[2 * rightChild + 2].used) {
                bstArray[2 * index + 2].data = bstArray[2 * rightChild + 2].data;
                bstArray[2 * rightChild + 2].used = false;
            }
        }
        // Case 4: Two children
        else {
            // Find inorder successor (smallest in right subtree)
            int successorIdx = findInorderSuccessor(index);
            if (successorIdx != -1) {
                // Replace current node's data with successor's data
                bstArray[index].data = bstArray[successorIdx].data;
                // Remove the successor node
                bstArray[successorIdx].used = false;
            }
        }
    }
}

// Display the BST array (index and value)
void displayBST() {
    cout << "BST:" << endl;
    for (int i = 0; i < SIZE; i++) {
        if (bstArray[i].used) {
            cout << "Index " << i << ": " << bstArray[i].data << endl;
        }
    }
}

int main() {
    int parentIndex, currentIndex, inputValue;

    // Input the root element
    cout << "Enter number: ";
    cin >> inputValue;
    maketree(inputValue);

    // Insert elements into the BST
    while (true) {
        cout << "Enter number: ";
        cin >> inputValue;
        if (inputValue == -1) { break; }
        parentIndex = currentIndex = 0;
        // Find the correct position for the new value
        while (currentIndex < SIZE && bstArray[currentIndex].used && inputValue != bstArray[currentIndex].data) {
            parentIndex = currentIndex;
            // Go left if value is less, right if greater
            if (inputValue < bstArray[parentIndex].data) {
                currentIndex = 2 * parentIndex + 1;
            } else {
                currentIndex = 2 * parentIndex + 2;
            }
        }
        // Handle duplicate or insert as left/right child
        if (inputValue == bstArray[parentIndex].data) {
            cout << inputValue << " is a duplicate" << endl;
        } else if (inputValue > bstArray[parentIndex].data) {
            setRightChild(parentIndex, inputValue);
        } else {
            setLeftChild(parentIndex, inputValue);
        }
    }

    // Traversing the BST
    cout << endl;
    cout << "Preorder traversal: ";
    preorderTraversal(0); // Print root, left, right
    cout << endl;
    cout << "Inorder traversal: ";
    inorderTraversal(0); // Print left, root, right
    cout << endl;
    cout << "Postorder traversal: ";
    postorderTraversal(0); // Print left, right, root
    cout << endl << endl;
    // Display the BST
    displayBST();
    cout << endl;
    // Deletion loop
    while (true) {
        cout << "Enter number to delete: ";
        cin >> inputValue;
        if (inputValue == -1) { break; }
        deleteNode(inputValue); // Attempt to delete node
        cout << endl;
        displayBST(); // Show tree after deletion
        cout << endl;
    }
    return 0;
}