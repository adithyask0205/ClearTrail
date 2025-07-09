// To find the Nth largest number in an array
#include<iostream>  // for input-output operations
#include<vector>    // for using vector container
#include<algorithm> // for using the sort() and unique() function
#include<functional> // for using the greater<> comparator
using namespace std;

// FindNthLargest class to perform operations for finding the nth largest in an array
class FindNthLargest {
    vector<int> numbers;    // vector to store the array of numbers
    int length;             // variable to store length of array
    int n;                  // value of n
    int nthValue;           // nth largest value
    bool hasError;          // to indicate error
    bool handleUnique;      // to handle unique elements

public:
    // taking input from the user
    void input() {
        hasError = false;
        
        // taking length of array
        cout << "Enter length of array: ";
        if (!(cin >> length) || length < 0) {
            cout << "Error: Invalid array length!" << endl;
            hasError = true;
            return;
        }
        
        if (length == 0) {
            cout << "Error: Array is empty!" << endl;
            hasError = true;
            return;
        }
        
        numbers.resize(length); // resizing the vector to the length of the array

        // taking values
        cout << "Enter elements of the array: " << endl;
        for (int i = 0; i < length; i++) {
            if (!(cin >> numbers[i])) {
                cout << "Error: Invalid input at position " << i + 1 << "!" << endl;
                hasError = true;
                return;
            }
        }

        // asking whether to handle unique elements
        cout << "Do you want to find Nth largest unique element? (1 for yes, 0 for no): ";
        int choice;
        if (!(cin >> choice)) {
            cout << "Error: Invalid choice!" << endl;
            hasError = true;
            return;
        }
        handleUnique = (choice == 1);

        // taking the value of N
        cout << "Enter N (should be between 1 and " << (handleUnique ? "number of unique elements" : length) << "): ";
        if (!(cin >> n)) {
            cout << "Error: Invalid N value!" << endl;
            hasError = true;
            return;
        }
    }

    // finding the Nth largest element
    void nthLargest() {
        if (hasError) return;
        
        // first sorting the array in descending order
        sort(numbers.begin(), numbers.end(), greater<int>());

        // If handling unique elements, remove duplicates
        if (handleUnique) {
            auto last = unique(numbers.begin(), numbers.end());
            numbers.erase(last, numbers.end());
        }

        // Check if n is within valid range
        if (n < 1 || n > numbers.size()) {
            cout << "Error: N is out of range! Valid range is 1 to " << numbers.size() << endl;
            nthValue = -1;
            hasError = true;
            return;
        }

        // largest is at index 0, second largest at index 1... nth largest at index n-1
        nthValue = numbers[n - 1];
    }

    // displaying the nth largest value
    void output() {
        if (hasError) {
            cout << "Cannot find Nth largest element due to errors." << endl;
            return;
        }
        cout << "Nth largest element is: " << nthValue << endl;
    }
};

int main() {
    // declaring the object
    FindNthLargest find;

    // calling the member functions
    find.input();
    find.nthLargest();
    find.output();
    return 0;
}