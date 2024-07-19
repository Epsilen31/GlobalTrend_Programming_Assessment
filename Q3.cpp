#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxGain(root, maxSum);
        return maxSum;
    }

private:
    int maxGain(TreeNode* node, int& maxSum) {
        if (node == NULL) {
            return 0;
        }
        // Recursively get the maximum gain from left and right subtrees
        int leftGain = max(maxGain(node->left, maxSum), 0); // Ignore paths with negative sum
        int rightGain = max(maxGain(node->right, maxSum), 0);
        // The price to start a new path where `node` is the highest node
        int newPathSum = node->val + leftGain + rightGain;
        // Update maxSum if it's better to start a new path
        maxSum = max(maxSum, newPathSum);
        // For recursion, return the maximum gain if continuing the same path
        return node->val + max(leftGain, rightGain);
    }
};
// Helper function to create a new tree node
TreeNode* newNode(int val) {
    TreeNode* node = new TreeNode(val);
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    // Construct the tree
    TreeNode* root = newNode(-10);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);
    Solution solution;
    cout << "The maximum path sum is: " << solution.maxPathSum(root) << endl;
    return 0;
}

// output
// The maximum path sum is: 42