#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to find the maximum difference between any two elements in an array
int maxDifference(const vector<int>& nums) {
    if (nums.empty()) {
        cerr << "Array is empty. Cannot compute difference." << endl;
        return 0;
    }

    int minElement = nums[0];
    int maxElement = nums[0];

    // Traverse the array to find the minimum and maximum elements
    for (int num : nums) {
        if (num < minElement) {
            minElement = num;
        }
        if (num > maxElement) {
            maxElement = num;
        }
    }

    // The maximum difference is between the maximum and minimum elements
    return maxElement - minElement;
}

int main() {
    vector<int> nums = {2, 9, 5, 1, 7, 3};

    int maxDiff = maxDifference(nums);
    cout << "The maximum difference between any two elements is: " << maxDiff << endl;

    return 0;
}
//  output
// The maximum difference between any two elements is: 8