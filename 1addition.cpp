// Addition of two big numbers (big number - 4098 bytes)
#include<iostream> // for input-output operations
using namespace std;

// BigNumberAdder class for addition of big numbers
class BigNumberAdder {
    // 3 arrays to store big numbers
    char firstNumber[4098]; // stores first number
    char secondNumber[4098]; // stores second number
    char result[8200]; // stores result

public:
    // takes input of big numbers from the user
    void input() {
        cout << "Enter first number: ";
        cin >> firstNumber;
        cout << "Enter second number: ";
        cin >> secondNumber;
    }

    // performs addition of numbers
    void add() {
        // length of both numbers
        int len1 = 0, len2 = 0;

        // length of first number
        while (firstNumber[len1] != '\0') {
            len1++;
        }

        // length of second number
        while (secondNumber[len2] != '\0') {
            len2++;
        }

        // iterating variables
        int i = len1 - 1; // for first number
        int j = len2 - 1; // for second number
        int k = 0;

        int carry = 0; // variable for storing carry

        char tempResult[8200] = {0}; // temporary array to store the digits

        // addition
        while (i >= 0 || j >= 0 || carry > 0) {
            // initializes the face value as 0
            int sum = 0;

            // addition of integers to the face value
            if (i >= 0) {
                sum += firstNumber[i] - '0'; // subtracting '0' to get rid of ASCII code
                i--;
            } 
            if (j >= 0) {
                sum += secondNumber[j] - '0';
                j--;
            }

            // adding the carry from the previous iteration
            sum += carry;

            // storing the ones digit into the temporary result, and carrying forward the tens digit
            tempResult[k] = (sum % 10) + '0';
            carry = sum / 10;
            k++;
        }

        // reversing and storing the actual sum into the result array
        int idx = 0;
        for (int m = k - 1; m >= 0; m--) {
            result[idx] = tempResult[m];
            idx++;
        }
        result[idx] = '\0';
    }

    // displays the output on the console
    void output() {
        cout << "Sum: " << result << endl;
    }
};

int main() {
    BigNumberAdder adder;
    adder.input();
    adder.add();
    adder.output();
    return 0;
}