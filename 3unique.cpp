//Print all the unique elements of an array.

#include<iostream> // Required for input/output stream operations (cin, cout)
#include<vector>   // Required for using vector container

using namespace std;

int main() {
    int arrayLength;
    
    cout << "Enter length of array: ";
    cin >> arrayLength;

    // Create a vector to store the input array elements
    vector<int> inputArray(arrayLength);
    // Vector to store unique elements
    vector<int> uniqueElements;

    // Input array elements from the user
    cout << "Enter elements of array: " << endl;
    for (int index = 0; index < arrayLength; index++) {
        cin >> inputArray[index];
    }
    
    // Find unique elements
    for (int i = 0; i < arrayLength; i++) {
        bool isUnique = true; // Assume current element is unique

        // Check if current element appeared before
        for (int j = 0; j < i; j++) {
            if (inputArray[i] == inputArray[j]) {
                isUnique = false; // Not unique
                break;
            }
        }

        // If unique, add to uniqueElements vector
        if (isUnique) {
            uniqueElements.push_back(inputArray[i]);
        }
    }

    // Output the unique elements
    cout << "Unique elements: { ";
    for (int i = 0; i < uniqueElements.size(); i++) {
        cout << uniqueElements[i] << " ";
    }
    cout << "}" << endl;

    return 0;
}