#include <iostream>
#include <cctype> // For isalpha function
#include <string>

using namespace std;

// Function to check if the string contains only alphabetic characters
bool isAlphabetic(const string& str) {
    for (char ch : str) {
        if (!isalpha(ch)) {
            return false;
        }
    }
    return true;
}

int main() {
    string input;
    cout << "Enter a string to check if it contains only alphabetic characters: ";
    cin >> input;

    if (isAlphabetic(input)) {
        cout << "The string contains only alphabetic characters." << endl;
    } else {
        cout << "The string contains non-alphabetic characters." << endl;
    }

    return 0;
}

// output
// Enter a string to check if it contains only alphabetic characters: hello world
// The string contains only alphabetic characters.

// Enter a string to check if it contains only alphabetic characters: hwll0
// The string contains non-alphabetic characters.
