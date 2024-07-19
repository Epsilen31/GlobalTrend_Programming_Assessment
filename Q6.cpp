#include <iostream>
using namespace std;

// Function to calculate the factorial of a number
unsigned long long factorial(int n) {
    if (n < 0) {
        cerr << "Factorial is not defined for negative numbers." << endl;
        return 0;
    }

    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int num;
    cout << "Enter a number to find its factorial: ";
    cin >> num;

    unsigned long long fact = factorial(num);
    cout << "Factorial of " << num << " is: " << fact << endl;

    return 0;
}

// output
// Enter a number to find its factorial: 5
// Factorial of 5 is: 120