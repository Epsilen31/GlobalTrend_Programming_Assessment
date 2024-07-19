#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Helper function to reverse a portion of the array
void reverse(vector<int>& nums, int start, int end) {
    while (start < end) {
        swap(nums[start], nums[end]);
        start++;
        end--;
    }
}
// Function to rotate the array to the right by k steps
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;  // Handle cases where k is greater than the array size
    // Step 1: Reverse the entire array
    reverse(nums, 0, n - 1);
    // Step 2: Reverse the first k elements
    reverse(nums, 0, k - 1);

    // Step 3: Reverse the remaining n-k elements
    reverse(nums, k, n - 1);
}
int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    cout << "Original array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    rotate(nums, k);
    cout << "Rotated array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}



// output
// Original array: 1 2 3 4 5 6 7 
// Rotated array: 5 6 7 1 2 3 4 