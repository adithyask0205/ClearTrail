// To insert, delete, and traverse (inorder, preorder, postorder) a BST using array
#include<iostream>  // for input-output operations
using namespace std;

// Array Binary Search Tree Class
class ArrayBST {
    struct BSTNode {
        int data;  // value stored in the node
        bool used;  // to indicate whether the node is already used or not
    };
    static const int SIZE = 100;
    BSTNode bst[SIZE];  // declaring an ArrayBST structure object, which will be the BST
public:
    // constructor
    ArrayBST() {
        for (int i = 0; i < SIZE; i++) {
            bst[i].used = false;
        }
    }

    // making the tree
    void maketree(int root) {
        bst[0].data = root;
        bst[0].used = true;
        for (int i = 1; i < SIZE; i++) {
            bst[i].used = false;
        }
    }

    // setting right child
    void setRightChild(int parentIndex, int value) {
        // Right child index = 2*i + 2
        int rightIndex = 2 * parentIndex + 2;
        // when child index is out of bounds
        if (rightIndex >= SIZE) {
            cout << "Array overflow" << endl;
        }
        // when child index is already used  
        else if (bst[rightIndex].used) {
            cout << "Invalid insertion" << endl;
        }
        // when child index is available and in bound
        else {
            bst[rightIndex].data = value;
            bst[rightIndex].used = true;
        }
    }

    // setting left child
    void setLeftChild(int parentIndex, int value) {
        // Left child index = 2*i + 1
        int leftIndex = 2 * parentIndex + 1;
        // when child index is out of bounds
        if (leftIndex >= SIZE) {
            cout << "Array overflow" << endl;
        }
        // when child index is already used 
        else if (bst[leftIndex].used) {
            cout << "Invalid insertion" << endl;
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
        int parentIndex = 0, currentIndex = 0;
        // continues searching for unused node withing bounded size while data is not existing.
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
    void inorderTraversal(int index) {
        if (index < SIZE && bst[index].used) {
            inorderTraversal(2 * index + 1);    // left child
            cout << bst[index].data << " ";     // root
            inorderTraversal(2 * index + 2);    // right child
        }
    }

    // preorder traversal does: root -> left child -> right child
    void preorderTraversal(int index) {
        if (index < SIZE && bst[index].used) {
            cout << bst[index].data << " ";     // root
            preorderTraversal(2 * index + 1);   // left child
            preorderTraversal(2 * index + 2);   // right child
        }
    }

    // postorder traversal goes: left child -> right child -> root
    void postorderTraversal(int index) {
        if (index < SIZE && bst[index].used) {
            postorderTraversal(2 * index + 1);  // left child
            postorderTraversal(2 * index + 2);  // right child
            cout << bst[index].data << " ";     // root
        }
    }

    // deleting a node
    void deleteNode(int value) {
        // initializing first index
        int index = 0;
        // only traverse through used nodes
        while (index < SIZE && bst[index].used) {
            if (bst[index].data == value) { break; }    // if value found, exit with that index
            if (value < bst[index].data) { index = 2 * index + 1; } // if value less than current node, move to left node
            else { index = 2 * index + 2; }     // if value greater than current node, move to right node
        }
        // replacing with successor
        if (index < SIZE && bst[index].used && bst[index].data == value) {
            // getting indices of both left and right child
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;

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
                if (2 * leftChild + 1 < SIZE && bst[2 * leftChild + 1].used) {
                    bst[2 * index + 1].data = bst[2 * leftChild + 1].data;
                    bst[2 * leftChild + 1].used = false;
                }
                if (2 * leftChild + 2 < SIZE && bst[2 * leftChild + 2].used) {
                    bst[2 * index + 2].data = bst[2 * leftChild + 2].data;
                    bst[2 * leftChild + 2].used = false;
                }
            }
            
            // Case 3:  when only right child is present
            else if (!hasLeft && hasRight) {
                bst[index].data = bst[rightChild].data;
                bst[rightChild].used = false;
                if (2 * rightChild + 1 < SIZE && bst[2 * rightChild + 1].used) {
                    bst[2 * index + 1].data = bst[2 * rightChild + 1].data;
                    bst[2 * rightChild + 1].used = false;
                }
                if (2 * rightChild + 2 < SIZE && bst[2 * rightChild + 2].used) {
                    bst[2 * index + 2].data = bst[2 * rightChild + 2].data;
                    bst[2 * rightChild + 2].used = false;
                }
            }
            
            // Case 4: when both child are present
            else {
                int successorIdx = findInorderSuccessor(bst, index, SIZE);
                if (successorIdx != -1) {
                    bst[index].data = bst[successorIdx].data;
                    bst[successorIdx].used = false;
                }
            }
        }
    }

    // displaying BST
    void displayBST() {
        cout << "BST:" << endl;
        for (int i = 0; i < SIZE; i++) {
            if (bst[i].used) {
                cout << "Index " << i << ": " << bst[i].data << endl;
            }
        }
    }
};

int findInorderSuccessor(ArrayBST::BSTNode bst[], int index, int SIZE) {
    int rightChild = 2 * index + 2;
    if (rightChild >= SIZE || !bst[rightChild].used) return -1;
    int current = rightChild;
    while (2 * current + 1 < SIZE && bst[2 * current + 1].used) {
        current = 2 * current + 1;
    }
    return current;
}

int main() {
    // declaring bst array object
    ArrayBST bstArray;
    // taking first root element of bst
    int inputValue;
    cout << "Enter number: ";
    cin >> inputValue;
    // declaring the bst
    bstArray.maketree(inputValue);
    // inserting further nodes
    while (true) {
        cout << "Enter number: ";
        cin >> inputValue;
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
    while (true) {
        cout << "Enter number to delete: ";
        cin >> inputValue;
        if (inputValue == -1) { break; }
        bstArray.deleteNode(inputValue);
        cout << endl;
        bstArray.displayBST();
        cout << endl;
    }
}