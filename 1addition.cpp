//Add two big numbers (big number - 4098 bytes)

#include<iostream> // Required for input/output stream operations (cin, cout)

using namespace std;

// Function to add two big numbers represented as character arrays
void addBigNumbers(const char firstNumber[], const char secondNumber[], char result[]) {
    int len1 = 0, len2 = 0;
    // Calculate length of firstNumber
    while (firstNumber[len1] != '\0') {len1++;}
    // Calculate length of secondNumber
    while (secondNumber[len2] != '\0') {len2++;}
    
    int i = len1 - 1; // Index for firstNumber
    int j = len2 - 1; // Index for secondNumber
    int carry = 0;    // Carry for addition
    int k = 0;        // Index for result (in reverse)
    char tempResult[4100] = {0}; // Temporary result array (reverse order)
    
    // Add digits from right to left
    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;
        if (i >= 0) {
            sum += firstNumber[i] - '0';
            i--;
        }
        if (j >= 0) {
            sum += secondNumber[j] - '0';
            j--;
        }
        tempResult[k++] = (sum % 10) + '0'; // Store current digit
        carry = sum / 10;                   // Update carry
    }
    // Reverse the result to get the correct order
    int idx = 0;
    for (int m = k - 1; m >= 0; m--) {
        result[idx++] = tempResult[m];
    }
    result[idx] = '\0';
}

int main() {
    char firstNumber[4098], secondNumber[4098];
    char result[8200];
    
    cout << "Enter first number: ";
    cin >> firstNumber;
    
    cout << "Enter second number: ";
    cin >> secondNumber;
    
    // Call function to add big numbers
    addBigNumbers(firstNumber, secondNumber, result);
    
    cout << "Sum: " << result << endl;
    return 0;
}