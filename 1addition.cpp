// Addition of two big numbers (big number - 4098 bytes)
#include<iostream> // for input-output operations
using namespace std;

// Constants
const int MAX_DIGITS = 4098;
const int MAX_RESULT_SIZE = 4100;

// BigNumberAdder class for addition of big numbers
class BigNumberAdder {
    // 3 arrays to store big numbers
    char firstNumber[MAX_DIGITS]; // stores first number
    char secondNumber[MAX_DIGITS]; // stores second number
    char result[MAX_RESULT_SIZE]; // stores result

    // Input validation function
    bool isValidNumber(const char* num) {
        for (int i = 0; num[i] != '\0'; ++i) {
            if (num[i] < '0' || num[i] > '9')
                return false; // Non-digit character found
        }
        return true;
    }

    //Function to get length of character array
    int numLen(char* num){
        int len = 0;
        while (num[len] != '\0') {
            len++;
        }
        return len;
    }

    // Function to remove leading zeros
    void removeLeadingZeros(char* num) {
        int len = numLen(num);
        int start = 0;
        
        // Find first non-zero digit
        while (start < len - 1 && num[start] == '0') {
            start++;
        }
        // Shift the number to remove leading zeros
        if (start > 0) {
            for (int i = 0; i <= len - start; i++) {
                num[i] = num[i + start];
            }
        }
    }

public:
    // takes input of big numbers from the user
    void input() {
        bool validInput = false;
        while (!validInput) {
            cout << "Enter first number: ";
            cin.getline(firstNumber, MAX_DIGITS);
            
            if (!isValidNumber(firstNumber)) {
                cout << "Error: Please enter only digits (0-9)!" << endl;
                continue;
            }
            
            cout << "Enter second number: ";
            cin.getline(secondNumber, MAX_DIGITS);
            if (!isValidNumber(secondNumber)) {
                cout << "Error: Please enter only digits (0-9)!" << endl;
                continue;
            }
            
            validInput = true;
        }
        
        // Remove leading zeros from input
        removeLeadingZeros(firstNumber);
        removeLeadingZeros(secondNumber);
    }

    // performs addition of numbers
    void add() {
        int len1 = numLen(firstNumber);   // Length of first number
        int len2 = numLen(secondNumber);  // Length of second number
        int i = len1 - 1; // Index for firstNumber (rightmost digit)
        int j = len2 - 1; // Index for secondNumber (rightmost digit)
        int k = 0;        // Index for tempResult
        int carry = 0;    // Carry for addition
        char tempResult[MAX_RESULT_SIZE] = {0}; // Temporary array to store sum in reverse order
        // Add digits from right to left
        while (i >= 0 || j >= 0 || carry > 0) {
            // initializes the face value as 0
            int sum = 0;

            // addition of integers to the face value
            if (i >= 0) {
                sum += firstNumber[i] - '0'; // Convert char to int
                i--;
            } 
            if (j >= 0) {
                sum += secondNumber[j] - '0';
                j--;
            }
            sum += carry; // Add carry from previous step
            tempResult[k] = (sum % 10) + '0'; // Store ones digit as char
            carry = sum / 10; // Update carry
            k++;
        }

        // reversing and storing the actual sum into the result array
        int idx = 0;
        for (int m = k - 1; m >= 0; m--) {
            result[idx] = tempResult[m];
            idx++;
        }
        result[idx] = '\0';
        
        // Remove leading zeros from result (if any)
        removeLeadingZeros(result);
    }

    // displays the output on the console
    void output() {
        cout << "Sum: " << result << endl;
    }
};

int main() {
    BigNumberAdder adder; // Create an object of BigNumberAdder
    adder.input();        // Take input from user
    adder.add();          // Perform addition
    adder.output();       // Display result
    return 0;
}