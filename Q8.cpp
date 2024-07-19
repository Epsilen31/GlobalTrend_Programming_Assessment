#include <iostream>
using namespace std;

// Function to compute the GCD of two numbers using the Euclidean algorithm
int gcd(int a, int b) {
    // Handle the case where one of the numbers is zero
    if (b == 0) {
        return a;
    }
    // Recursive call with parameters (b, a % b)
    return gcd(b, a % b);
}

int main() {
    int a, b;
    cout << "Enter two numbers to find their GCD: ";
    cin >> a >> b;

    int result = gcd(a, b);
    cout << "The GCD of " << a << " and " << b << " is: " << result << endl;

    return 0;
}

// output
// Enter two numbers to find their GCD: 10 2
// The GCD of 10 and 2 is: 2
