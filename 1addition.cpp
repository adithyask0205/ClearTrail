//Add two big numbers (big number - 4098 bytes)

#include<iostream>
#include<string>

using namespace std;

string add(string a, string b) {
    int carry = 0;
    int i = a.length();
    int j = b.length();

    string result = "";

    while (i>0 || j>0 || carry>0) {
        int sum = 0;

        if (i>0) {
            sum += a[i-1] - '0';
            i--;
        }

        if (j>0) {
            sum += b[j-1] - '0';
            j--;
        }

        sum += carry;
        carry = sum/10;
        sum = sum % 10;
        result = char(sum + '0') + result;
    }

    return result;
}

int main() {
    string a,b;
    cout << "Enter first number: ";
    cin >> a;

    cout << "Enter second number: ";
    cin >> b;

    string result = add(a, b);
    cout << "Sum: " << result << endl;

    return 0;
}