// To merge two arrays of different sizes and sort in ascending or descending order according to user input
#include<iostream>  // for input-output operations
#include<vector>    // for using vector containers
#include<algorithm> // for using the sort() function
#include<functional> // for using the greater<> comparator
using namespace std;

// ArrayMerger to perform operations of merging and sorting two arrays
class ArrayMerger {
    vector<int> firstArray;        // vector to store the first array of elements
    vector<int> secondArray;       // vector to store the second array of elements
    vector<int> mergedArray;       // vector to store the merged array
    int size1, size2;              // lengths of first and second arrays respectively
    int sortChoice;                // to decide ascending or descending sort
    bool hasError;                 // flag to indicate error state

public:
    // taking inputs from the user
    void input() {
        hasError = false;
        
        // taking size inputs from the user
        cout << "Enter size of the first array: ";  // for first array
        if (!(cin >> size1) || size1 < 0) {
            cout << "Error: Invalid size for first array!" << endl;
            hasError = true;
            return;
        }
        
        cout << "Enter size of the second array: "; // for second array
        if (!(cin >> size2) || size2 < 0) {
            cout << "Error: Invalid size for second array!" << endl;
            hasError = true;
            return;
        }

        // resizing both arrays accordingly
        firstArray.resize(size1);
        secondArray.resize(size2);

        // taking elements for first array
        cout << "Enter elements for first array: " << endl;
        for (int i = 0; i < size1; i++) {
            if (!(cin >> firstArray[i])) {
                cout << "Error: Invalid input at position " << i + 1 << " in first array!" << endl;
                hasError = true;
                return;
            }
        }

        // taking elements for second array
        cout << "Enter elements for second array: " << endl;
        for (int i = 0; i < size2; i++) {
            if (!(cin >> secondArray[i])) {
                cout << "Error: Invalid input at position " << i + 1 << " in second array!" << endl;
                hasError = true;
                return;
            }
        }
        // Input sort choice with validation
        cout << "Sort in: \n1. Ascending \n2. Descending \n(1/2): ";
        if (!(cin >> sortChoice) || (sortChoice != 1 && sortChoice != 2)) {
            cout << "Error: Invalid sort choice! Please enter 1 or 2." << endl;
            hasError = true;
            return;
        }
    }

    // merging both arrays
    void merge() {
        if (hasError) return;
        mergedArray.clear();
        mergedArray = firstArray;
        mergedArray.insert(mergedArray.end(), secondArray.begin(), secondArray.end());
    }

    // sorting the merged array
    void sortMerged() {
        if (hasError) return;
        
        // 1. Ascending
        if (sortChoice == 1) {
            sort(mergedArray.begin(), mergedArray.end());
            cout << "Merged (Ascending): ";
        // 2. Descending
        } else {
            sort(mergedArray.begin(), mergedArray.end(), greater<int>());
            cout << "Merged (Descending): ";
        }
    }

    // displaying the output
    void output() {
        if (hasError) {
            cout << "Cannot merge arrays due to errors." << endl;
            return;
        }
        if (mergedArray.empty()) {
            cout << "No elements to merge." << endl;
            return;
        }
        cout << "{ ";
        for (int val : mergedArray) {
            cout << val << " ";
        }
        cout << "}" << endl;
    }
};

int main() {
    // initializing the object
    ArrayMerger merger;

    // calling the member functions
    merger.input();
    merger.merge();
    merger.sortMerged();
    merger.output();
    return 0;
}