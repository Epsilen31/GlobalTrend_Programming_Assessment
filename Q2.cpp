#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
int lengthOfLongestSubstring(string s) {
   // To store the most recent index of each character
    unordered_map<char, int> charIndexMap; 
   // To store the maximum length of substring without repeating characters
    int maxLength = 0;     
// Start index of the current window
    int start = 0;                          
    for (int end = 0; end < s.length(); ++end) {
        char currentChar = s[end];
        // If the character is found in the map and is within the current window
        if (charIndexMap.find(currentChar) != charIndexMap.end() && charIndexMap[currentChar] >= start) {
            // Move the start to the right of the duplicate character's last known position
            start = charIndexMap[currentChar] + 1;
        }
        // Update the most recent index of the current character
        charIndexMap[currentChar] = end;
        // Calculate the length of the current window and update maxLength if necessary
        maxLength = max(maxLength, end - start + 1);
    }

    return maxLength;
}

int main() {
    string s = "abcabcbb";
    cout << "The length of the longest substring without repeating characters is: " << lengthOfLongestSubstring(s) << endl;

    s = "bbbbb";
    cout << "The length of the longest substring without repeating characters is: " << lengthOfLongestSubstring(s) << endl;

    s = "pwwkew";
    cout << "The length of the longest substring without repeating characters is: " << lengthOfLongestSubstring(s) << endl;

    s = "aab";
    cout << "The length of the longest substring without repeating characters is: " << lengthOfLongestSubstring(s) << endl;

    s = "dvdf";
    cout << "The length of the longest substring without repeating characters is: " << lengthOfLongestSubstring(s) << endl;

    return 0;
}

// output 
// The length of the longest substring without repeating characters is: 3
// The length of the longest substring without repeating characters is: 1
// The length of the longest substring without repeating characters is: 3
// The length of the longest substring without repeating characters is: 2
// The length of the longest substring without repeating characters is: 3