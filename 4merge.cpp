//To merge two arrays of different sizes. Sort in ascending/descending based on user input

#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

int main() {
    int n1, n2;
    cout << "Enter size of first array: ";
    cin >> n1;

    cout << "Enter size of second array: ";
    cin >> n2;

    vector<int> arr1(n1);
    vector<int> arr2(n2);

    cout << "Enter elements of first array: " << endl;
    for (int i = 0; i < n1; i++) { cin >> arr1[i]; }
    
    cout << "Enter elements of second array: " << endl;
    for(int i = 0; i < n2; i++) { cin >> arr2[i]; }

    vector<int> arr_merged;
    for (int i = 0; i < n1 + n2; i++) {
        if (i < n1) { arr_merged.push_back(arr1[i]); }
        else { arr_merged.push_back(arr2[i - n1]); }
    }

    int choice;
    cout << "Sort in: \n1. Ascending \n2. Descending \n(1/2): ";
    cin >> choice;

    if (choice == 1) { 
        sort(arr_merged.begin(), arr_merged.end());

        cout << "Merged (Ascending): ";
    }
    else {
        sort(arr_merged.begin(), arr_merged.end(), greater<int>());
        
        cout << "Merged (Descending): ";
    }

    cout << "{ ";
    for (int i = 0; i < n1 + n2; i++) {
        cout << arr_merged[i] << " ";
    }
    cout << "}";

    return 0;
}