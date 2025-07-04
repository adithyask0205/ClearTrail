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
public:
    // taking inputs from the user
    void input() {
        // taking size inputs from the user
        cout << "Enter size of the first array: ";  // for first array
        cin >> size1;
        cout << "Enter size of the second array: "; // for second array
        cin >> size2;

        // resizing both arrays accordingly
        firstArray.resize(size1);
        secondArray.resize(size2);

        // taking elements for first array
        cout << "Enter elements for first array: " << endl;
        for (int i = 0; i < size1; i++) {
            cin >> firstArray[i];
        }

        // taking elements for second array
        cout << "Enter elements for second array: " << endl;
        for (int i = 0; i < size2; i++) {
            cin >> secondArray[i];
        }

        // sorting choice
        cout << "Sort in: \n1. Ascending \n2. Descending \n(1/2): ";
        cin >> sortChoice;
    }

    // merging both arrays
    void merge() {
        mergedArray.clear(); // clearing the array to make sure no element already resides
        // adding first array
        for (int i = 0; i < size1; i++) {
            mergedArray.push_back(firstArray[i]);
        }
        // adding second array
        for (int i = 0; i < size2; i++) {
            mergedArray.push_back(secondArray[i]);
        }
    }

    // sorting the merged array
    void sortMerged() {
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
        cout << "{ ";
        for (int i = 0; i < mergedArray.size(); i++) {
            cout << mergedArray[i] << " ";
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