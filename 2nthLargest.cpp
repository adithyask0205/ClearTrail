// To find the Nth largest number in an array
#include<iostream>  // for input-output operations
#include<vector>    // for using vector container
#include<algorithm> // for using the sort() function
#include<functional> // for using the greater<> comparator
using namespace std;

// FindNthLargest class to perform operations for finding the nth largest in an array
class FindNthLargest {
    vector<int> numbers;    // vector to store the array of numbers
    int length;             // variable to store length of array
    int n;                  // value of n
    int nthValue;           // nth largest value
public:
    // taking input from the user
    void input() {
        // taking length of array
        cout << "Enter length of array: ";
        cin >> length;
        numbers.resize(length); // resizing the vector to the length of the array

        // taking values
        cout << "Enter elements of the array: " << endl;
        for (int i = 0; i < length; i++) {
            cin >> numbers[i];
        }

        // taking the value of N
        cout << "Enter N: ";
        cin >> n;
    }

    // finding the Nth largest element
    void nthLargest() {
        // first sorting the array in descending order
        sort(numbers.begin(), numbers.end(), greater<int>());

        // Check if n is within valid range
        if (n < 1 || n > length) {
            cout << "Error: N is out of range!" << endl;
            nthValue = -1;
            return;
        }

        // largest is at index 0, second largest at index 1... nth largest at index n-1
        nthValue = numbers[n - 1];
    }

    // displaying the nth largest value
    void output() {
        if (nthValue != -1)
            cout << "Nth largest element is: " << nthValue  << endl;
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