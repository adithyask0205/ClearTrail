//To merge two arrays of different sizes. Sort in ascending/descending based on user input

#include<iostream>      // Required for input/output stream operations (cin, cout)
#include<vector>        // Required for using vector container
#include<algorithm>     // Required for sort function
#include<functional>    // Required for greater comparator

using namespace std;

int main() {
    int sizeFirst, sizeSecond;
    // Prompt user for the size of the first array
    cout << "Enter size of first array: ";
    cin >> sizeFirst;

    // Prompt user for the size of the second array
    cout << "Enter size of second array: ";
    cin >> sizeSecond;

    // Create vectors to store the array elements
    vector<int> firstArray(sizeFirst);
    vector<int> secondArray(sizeSecond);

    // Input elements for the first array
    cout << "Enter elements of first array: " << endl;
    for (int i = 0; i < sizeFirst; i++) {
        cin >> firstArray[i];
    }
    
    // Input elements for the second array
    cout << "Enter elements of second array: " << endl;
    for (int i = 0; i < sizeSecond; i++) {
        cin >> secondArray[i];
    }

    // Merge the two arrays into one
    vector<int> mergedArray;
    for (int i = 0; i < sizeFirst + sizeSecond; i++) {
        if (i < sizeFirst) {
            mergedArray.push_back(firstArray[i]);
        } else {
            mergedArray.push_back(secondArray[i - sizeFirst]);
        }
    }

    int choice;
    cout << "Sort in: \n1. Ascending \n2. Descending \n(1/2): ";
    cin >> choice;

    if (choice == 1) { 
        sort(mergedArray.begin(), mergedArray.end()); // Ascending order
        cout << "Merged (Ascending): ";
    } else {
        sort(mergedArray.begin(), mergedArray.end(), greater<int>()); // Descending order
        cout << "Merged (Descending): ";
    }

    // Output the merged and sorted array
    cout << "{ ";
    for (int i = 0; i < sizeFirst + sizeSecond; i++) {
        cout << mergedArray[i] << " ";
    }
    cout << "}" << endl;

    return 0;
}