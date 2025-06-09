//Print all the unique elements of an array.

#include<iostream>
#include<vector>

using namespace std;

int main() {
    int length;
    
    cout << "Enter length of array: ";
    cin >> length;

    vector<int> arr(length);
    vector<int> unique;

    cout << "Enter elements of array: " << endl;
    for (int i=0; i<length; i++) {
        cin >> arr[i];
    }
    
    for (int i=0; i<length; i++) {
        int uniqueness = 1;

        for (int j=0; j<i; j++) {
            if (arr[i] == arr[j]) {
                uniqueness = 0;
                break;
            }
        }

        if (uniqueness) {
            unique.push_back(arr[i]);
        }
    }

    cout << "Unique elements: { ";
    for (int i=0; i < unique.size(); i++) {
        cout << unique[i] << " ";
    }
    cout << "}";

    return 0;
}