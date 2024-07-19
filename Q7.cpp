#include <iostream>

using namespace std;

// Function to compute the sum of the digits of a given number
int sumOfDigits(int num) {
    // Handle negative numbers by taking the absolute value
    num = abs(num);

    int sum = 0;
    while (num > 0) {
        sum += num % 10; // Add the last digit to the sum
        num /= 10;       // Remove the last digit
    }
    return sum;
}

int main() {
    int num;
    cout << "Enter a number to compute the sum of its digits: ";
    cin >> num;

    int sum = sumOfDigits(num);
    cout << "Sum of the digits of " << num << " is: " << sum << endl;

    return 0;
}	

// output
// Enter a number to compute the sum of its digits: 123
// Sum of the digits of 123 is: 6
