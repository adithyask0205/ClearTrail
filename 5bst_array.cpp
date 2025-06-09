//Insert, Delete, Traverse (in, pre, post) a Binary Search Tree using Array

#include<iostream>
using namespace std;

const int SIZE = 100;

//Structure
struct node {
    int data;
    int used;
} node[SIZE];

//Initialize
void maketree(int x) {
    node[0].data = x;
    node[0].used = true;

    for (int i=1; i<SIZE; i++) {
        node[i].used = false;
    }
}

//Right child
void setright(int p, int x) {
    int q = 2*p + 2;

    if (q >= SIZE) { cout << "Array overflow" << endl; }
    else if (node[q].used) { cout << "Invalid insertion" << endl; }
    else {
        node[q].data = x;
        node[q].used = true;
    }
}

//Left child
void setleft(int p, int x) {
    int q = 2*p + 1;

    if (q >= SIZE) { cout << "Array overflow" << endl; }
    else if (node[q].used) { cout << "Invalid insertion" << endl; }
    else {
        node[q].data = x;
        node[q].used = true;
    }
}

// left -> root -> right
void intrav(int idx) {
    if (idx < SIZE && node[idx].used) {
        intrav(2*idx + 1); 
        cout << node[idx].data << " ";
        intrav(2*idx + 2); 
    } 
}

// root -> left -> right
void pretrav(int idx) {
    if (idx < SIZE && node[idx].used) {
        cout << node[idx].data << " ";
        pretrav(2*idx + 1);
        pretrav(2*idx + 2);
    } 
}

// left -> right -> root
void postrav(int idx) {
    if (idx < SIZE && node[idx].used) {
        postrav(2*idx + 1);
        postrav(2*idx + 2);
        cout << node[idx].data << " ";
    } 
}

int findInorderSuccessor(int idx) {
    int rightChild = 2*idx + 2;
    if (rightChild >= SIZE || !node[rightChild].used) return -1;
    
    int current = rightChild;
    while (2*current + 1 < SIZE && node[2*current + 1].used) {
        current = 2*current + 1;
    }
    return current;
}

// Deletion
void deleteNode(int value) {
    int idx = 0;
    while (idx < SIZE && node[idx].used) {
        if (node[idx].data == value) { break; }
        if (value < node[idx].data) { idx = 2*idx + 1; }
        else { idx = 2*idx + 2; }
    }
    
    if (idx < SIZE && node[idx].used && node[idx].data == value) {
        int leftChild = 2*idx + 1;
        int rightChild = 2*idx + 2;
        bool hasLeft = (leftChild < SIZE && node[leftChild].used);
        bool hasRight = (rightChild < SIZE && node[rightChild].used);
        
        if (!hasLeft && !hasRight) {
            node[idx].used = false;
        }
        
        else if (hasLeft && !hasRight) {
            node[idx].data = node[leftChild].data;
            node[leftChild].used = false;
            
            if (2*leftChild + 1 < SIZE && node[2*leftChild + 1].used) {
                node[2*idx + 1].data = node[2*leftChild + 1].data;
                node[2*leftChild + 1].used = false;
            }
            if (2*leftChild + 2 < SIZE && node[2*leftChild + 2].used) {
                node[2*idx + 2].data = node[2*leftChild + 2].data;
                node[2*leftChild + 2].used = false;
            }
        }
        
        else if (!hasLeft && hasRight) {
            node[idx].data = node[rightChild].data;
            node[rightChild].used = false;
            
            if (2*rightChild + 1 < SIZE && node[2*rightChild + 1].used) {
                node[2*idx + 1].data = node[2*rightChild + 1].data;
                node[2*rightChild + 1].used = false;
            }
            if (2*rightChild + 2 < SIZE && node[2*rightChild + 2].used) {
                node[2*idx + 2].data = node[2*rightChild + 2].data;
                node[2*rightChild + 2].used = false;
            }
        }
        
        else {
            int successorIdx = findInorderSuccessor(idx);
            if (successorIdx != -1) {
                node[idx].data = node[successorIdx].data;
                node[successorIdx].used = false;
            }
        }
    }
}

//Display tree
void display() {
    cout << "BST:" << endl;
    for (int i = 0; i < SIZE; i++) {
        if (node[i].used) {
            cout << "Index " << i << ": " << node[i].data << endl;
        }
    }
}

int main() {
    int p, q, num;

    //Root element
    cout << "Enter number: ";
    cin >> num;

    maketree(num);

    //Inserting elements
    while(true) {
        cout << "Enter number: ";
        cin >> num;

        if (num == -1) { break;}

        p = q = 0;
        while(q < SIZE && node[q].used && num != node[q].data) {
            p = q;

            if (num < node[p].data) { q = 2*p + 1; }
            else { q = 2*p + 2; }
        }

        if (num == node[p].data) { cout << num << " is a duplicate" << endl; }
        else if (num > node[p].data) { setright(p, num); }
        else { setleft(p, num); }
    }

    //Traversing the BST
    cout << endl;

    cout << "Preorder traversal: ";
    pretrav(0);
    cout << endl;
    
    cout << "Inorder traversal: ";
    intrav(0);
    cout << endl;
    
    cout << "Postorder traversal: ";
    postrav(0);
    cout << endl;

    cout << endl;
    //Display
    display();
    cout << endl;

    //Deletion
    while(true) {
        cout << "Enter number to delete: ";
        cin >> num;
        if (num == -1) { break; }
        
        deleteNode(num);
        
        cout << endl;
        display();
        cout << endl;
    }

    return 0;
}