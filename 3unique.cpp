// to print all unique elements from the array
#include<iostream> // for input-output operations
#include<vector>   // for using vector containers
using namespace std;

// UniqueFinder class to perform operations for finding the unique elements of an array
class UniqueFinder {
    vector<int> inArray;        // vector to store array of input elements
    vector<int> uniqueArray;    // vector to store array of unique elements
    int length;                 // length of input array
public:
    // taking input from the user
    void input() {
        // taking length of array
        cout << "Enter length of array: ";
        cin >> length;

        inArray.resize(length); // resizing the vector according to the length of array

        // taking elements from the user
        cout << "Enter elements: " << endl;
        for (int i = 0; i < length; i++) {
            cin >> inArray[i];
        }
    }

    // transferring the unique elements into another array
    void findUnique() {
        uniqueArray.clear(); // clearing the array to make sure no element already resides

        // checking for unique elements
        for (int i = 0; i < length; i++) {
            bool isUnique = true;
            // Check if inArray[i] appeared before in the array
            for (int j = 0; j < i; j++) {
                if (inArray[i] == inArray[j]) {
                    isUnique = false;
                    break;
                }
            }
            // If unique, add to uniqueArray
            if (isUnique) {
                uniqueArray.push_back(inArray[i]);
            }
        }
    }

    // displaying array of unique elements
    void output() {
        cout << "Unique Elements: { ";
        for (int i = 0; i < uniqueArray.size(); i++) {
            cout << uniqueArray[i] << " ";
        } 
        cout << "}" << endl;
    }
};

int main() {
    UniqueFinder find;
    find.input();
    find.findUnique();
    find.output();
    return 0;
}