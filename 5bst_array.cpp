// To insert, delete, and traverse (inorder, preorder, postorder) a BST using array
#include<iostream>  // for input-output operations
using namespace std;

// Array Binary Search Tree Class
class ArrayBST {
    struct BSTNode {
        int data;  // value stored in the node
        bool used;  // to indicate whether the node is already used or not
    };
    static constexpr size_t SIZE = 100;
    BSTNode bst[SIZE];  // declaring an ArrayBST structure object, which will be the BST

    int findInorderSuccessor(size_t index) {
        size_t rightChild = 2 * index + 2;
        if (rightChild >= SIZE || !bst[rightChild].used) return -1;
        size_t current = rightChild;
        while (2 * current + 1 < SIZE && bst[2 * current + 1].used) {
            current = 2 * current + 1;
        }
        return static_cast<int>(current);
    }

public:
    // constructor
    ArrayBST() {
        for (size_t i = 0; i < SIZE; i++) {
            bst[i].used = false;
        }
    }

    // making the tree
    void maketree(int root) {
        bst[0].data = root;
        bst[0].used = true;
        for (size_t i = 1; i < SIZE; i++) {
            bst[i].used = false;
        }
    }

    // setting right child
    void setRightChild(size_t parentIndex, int value) {
        // Right child index = 2*i + 2
        size_t rightIndex = 2 * parentIndex + 2;
        // when child index is out of bounds
        if (rightIndex >= SIZE) {
            cout << "Warning: Array overflow - tree too deep!" << endl;
        }
        // when child index is already used  
        else if (bst[rightIndex].used) {
            cout << "Warning: Invalid insertion - position already occupied!" << endl;
        }
        // when child index is available and in bound
        else {
            bst[rightIndex].data = value;
            bst[rightIndex].used = true;
        }
    }

    // setting left child
    void setLeftChild(size_t parentIndex, int value) {
        // Left child index = 2*i + 1
        size_t leftIndex = 2 * parentIndex + 1;
        // when child index is out of bounds
        if (leftIndex >= SIZE) {
            cout << "Warning: Array overflow - tree too deep!" << endl;
        }
        // when child index is already used 
        else if (bst[leftIndex].used) {
            cout << "Warning: Invalid insertion - position already occupied!" << endl;
        }
        // when child index is available and in bound
        else {
            bst[leftIndex].data = value;
            bst[leftIndex].used = true;
        }
    }

    // inserting a node
    void insert(int value) {
        // initializing parent and current index as same
        size_t parentIndex = 0, currentIndex = 0;
        // continues searching for unused node within bounded size while data is not existing.
        while (currentIndex < SIZE && bst[currentIndex].used && value != bst[currentIndex].data) {
            // changing index of current node
            parentIndex = currentIndex;
            // storing into left child, if value is smaller than parent node
            if (value < bst[parentIndex].data) {
                currentIndex = 2 * parentIndex + 1;
            }
            // storing into right child, if value is greater than parent node
            else {
                currentIndex = 2 * parentIndex + 2;
            }
        }
        
        // Check for array overflow
        if (currentIndex >= SIZE) {
            cout << "Error: Cannot insert " << value << " - tree would exceed maximum depth!" << endl;
            return;
        }
        
        // warning when value is duplicate
        if (bst[parentIndex].used && value == bst[parentIndex].data) {
            cout << value << " is a duplicate" << endl;
        } 
        // setting right child when value is greater than parent
        else if (value > bst[parentIndex].data) {
            setRightChild(parentIndex, value);
        } 
        // setting left child when value is less than parent
        else {
            setLeftChild(parentIndex, value);
        }
    }

    // inorder traversal goes: left child -> root -> right child
    void inorderTraversal(size_t index) {
        if (index < SIZE && bst[index].used) {
            inorderTraversal(2 * index + 1);    // left child
            cout << bst[index].data << " ";     // root
            inorderTraversal(2 * index + 2);    // right child
        }
    }

    // preorder traversal does: root -> left child -> right child
    void preorderTraversal(size_t index) {
        if (index < SIZE && bst[index].used) {
            cout << bst[index].data << " ";     // root
            preorderTraversal(2 * index + 1);   // left child
            preorderTraversal(2 * index + 2);   // right child
        }
    }

    // postorder traversal goes: left child -> right child -> root
    void postorderTraversal(size_t index) {
        if (index < SIZE && bst[index].used) {
            postorderTraversal(2 * index + 1);  // left child
            postorderTraversal(2 * index + 2);  // right child
            cout << bst[index].data << " ";     // root
        }
    }

    // deleting a node
    void deleteNode(int value) {
        // initializing first index
        size_t index = 0;
        // only traverse through used nodes
        while (index < SIZE && bst[index].used) {
            if (bst[index].data == value) { break; }    // if value found, exit with that index
            if (value < bst[index].data) { index = 2 * index + 1; } // if value less than current node, move to left node
            else { index = 2 * index + 2; }     // if value greater than current node, move to right node
        }
        
        // Check if value was found
        if (index >= SIZE || !bst[index].used || bst[index].data != value) {
            cout << "Error: Value " << value << " not found in the tree!" << endl;
            return;
        }
        
        // replacing with successor
        if (index < SIZE && bst[index].used && bst[index].data == value) {
            // getting indices of both left and right child
            size_t leftChild = 2 * index + 1;
            size_t rightChild = 2 * index + 2;

            // checking whether each child is present or not
            bool hasLeft = (leftChild < SIZE && bst[leftChild].used);
            bool hasRight = (rightChild < SIZE && bst[rightChild].used);

            // Case 1: When no child is found
            if (!hasLeft && !hasRight) {
                bst[index].used = false;
            }
            // Case 2: When only left child is present
            else if (hasLeft && !hasRight) {
                bst[index].data = bst[leftChild].data;
                bst[leftChild].used = false;
                // Note: This is a simplified deletion that may not preserve all subtrees
                // For a complete BST deletion, more complex subtree movement would be needed
            }
            
            // Case 3: when only right child is present
            else if (!hasLeft && hasRight) {
                bst[index].data = bst[rightChild].data;
                bst[rightChild].used = false;
                // Note: This is a simplified deletion that may not preserve all subtrees
            }
            
            // Case 4: when both child are present
            else {
                int successorIdx = findInorderSuccessor(index);
                if (successorIdx != -1) {
                    bst[index].data = bst[successorIdx].data;
                    bst[successorIdx].used = false;
                    // Note: This is a simplified deletion that may not preserve all subtrees
                }
            }
        }
    }

    // displaying BST
    void displayBST() {
        cout << "BST:" << endl;
        bool hasNodes = false;
        for (size_t i = 0; i < SIZE; i++) {
            if (bst[i].used) {
                cout << "Index " << i << ": " << bst[i].data << endl;
                hasNodes = true;
            }
        }
        if (!hasNodes) {
            cout << "Tree is empty." << endl;
        }
    }
};

int main() {
    // declaring bst array object
    ArrayBST bstArray;
    
    // taking first root element of bst
    int inputValue;
    cout << "Enter root number: ";
    if (!(cin >> inputValue)) {
        cout << "Error: Invalid input!" << endl;
        return 1;
    }
    
    // declaring the bst
    bstArray.maketree(inputValue);
    
    // inserting further nodes
    cout << "Enter numbers to insert (enter -1 to stop): " << endl;
    while (true) {
        cout << "Enter number: ";
        if (!(cin >> inputValue)) {
            cout << "Error: Invalid input!" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        if (inputValue == -1) { break; }    // -1 to stop entering values
        bstArray.insert(inputValue);
    }
    cout << endl;

    // preorder traversal display
    cout << "Preorder traversal: ";
    bstArray.preorderTraversal(0);
    cout << endl;
    
    // inorder traversal display
    cout << "Inorder traversal: ";
    bstArray.inorderTraversal(0);
    cout << endl;
    
    // postorder traversal display
    cout << "Postorder traversal: ";
    bstArray.postorderTraversal(0);
    cout << endl << endl;

    //displaying the bst
    bstArray.displayBST();
    cout << endl;

    // deleting nodes from the bst
    cout << "Enter numbers to delete (enter -1 to stop): " << endl;
    while (true) {
        cout << "Enter number to delete: ";
        if (!(cin >> inputValue)) {
            cout << "Error: Invalid input!" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        if (inputValue == -1) { break; }
        bstArray.deleteNode(inputValue);
        cout << endl;
        bstArray.displayBST();
        cout << endl;
    }
}