//Find the Nth largest element in an array.

#include<iostream> // Required for input/output stream operations (cin, cout)
#include<vector>   // Required for using vector container
#include<algorithm> // Required for sort function

using namespace std;

int main() {
    int arrayLength, n;
    
    cout << "Enter length of array: ";
    cin >> arrayLength;

    // Create a vector to store the array elements
    vector<int> numbers(arrayLength);

    // Input array elements from the user
    cout << "Enter elements of array: " << endl;
    for (int index = 0; index < arrayLength; index++) {
        cin >> numbers[index];
    }

    // Input N from the user
    cout << "Enter N (for the Nth largest element): ";
    cin >> n;

    // Sort the array in descending order
    sort(numbers.begin(), numbers.end(), greater<int>());

    // The Nth largest element is at index N-1 after sorting
    int nthLargestValue = numbers[n-1];

    cout << "Nth largest element is: " << nthLargestValue << endl;

    return 0;
}