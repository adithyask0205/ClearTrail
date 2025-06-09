//Find the Nth largest element in an array.

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int length, n;
    
    cout << "Enter length of array: ";
    cin >> length;

    vector<int> arr(length);

    cout << "Enter elements of array: " << endl;
    for (int i=0; i<length; i++) {
        cin >> arr[i];
    }

    cout << "Enter N (for the Nth largest element): ";
    cin >> n;

    sort(arr.begin(), arr.end());

    int val = arr[n-1];

    cout << "Nth largest element is: " << val;

    return 0;
}