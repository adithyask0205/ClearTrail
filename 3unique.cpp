// Print all unique elements from an array using C++ OOP and STL (no std::string)
#include <iostream>        // For input-output operations (cin, cout)
#include <vector>          // For using vector containers
#include <unordered_set>   // For efficient unique element detection
using namespace std;

// UniqueFinder class to perform operations for finding the unique elements of an array
class UniqueFinder {
    vector<int> inputArray;        // Stores the input array of elements
    vector<int> uniqueElements;    // Stores the unique elements found
    int arrayLength;               // Length of the input array
    bool hasError;                 // Flag to indicate error state

public:
    // Function to take input from the user
    void input() {
        hasError = false;
        // taking length of array
        cout << "Enter length of array: ";
        if (!(cin >> arrayLength) || arrayLength <= 0) {
            cout << "Error: Invalid array length!" << endl;
            hasError = true;
            return;
        }
        inputArray.resize(arrayLength); // Resize vector to array length
        // taking array elements
        cout << "Enter elements: " << endl;
        for (int i = 0; i < arrayLength; i++) {
            if (!(cin >> inputArray[i])) {
                cout << "Error: Invalid input at position " << i + 1 << "!" << endl;
                hasError = true;
                return;
            }
        }
    }

    // transferring the unique elements into another array
    void findUnique() {
        if (hasError) return;
        uniqueElements.clear();
        unordered_set<int> seen;
        for (int i = 0; i < arrayLength; i++) {
            if (seen.find(inputArray[i]) == seen.end()) {
                uniqueElements.push_back(inputArray[i]);
                seen.insert(inputArray[i]);
            }
        }
    }

    // displaying array of unique elements
    void output() {
        if (hasError) {
            cout << "Cannot find unique elements due to errors." << endl;
            return;
        }
        if (arrayLength == 0) {
            cout << "No elements in the array." << endl;
            return;
        }
        if (uniqueElements.empty()) {
            cout << "No unique elements found." << endl;
            return;
        }
        cout << "Unique Elements: { ";
        for (int i = 0; i < uniqueElements.size(); i++) {
            cout << uniqueElements[i] << " ";
        }
        cout << "}" << endl;
        cout << "Total unique elements: " << uniqueElements.size() << endl;
    }
};

int main() {
    UniqueFinder finder; // Create object
    finder.input();      // Take input
    finder.findUnique(); // Find unique elements
    finder.output();     // Display result
    return 0;
}