#include <iostream>
#include <sstream>
#include <string>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        
        ostringstream out;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (node) {
                out << node->val << " ";
                q.push(node->left);
                q.push(node->right);
            } else {
                out << "# ";
            }
        }
        
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        
        istringstream in(data);
        string val;
        in >> val;
        
        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (!(in >> val)) break;
            if (val != "#") {
                node->left = new TreeNode(stoi(val));
                q.push(node->left);
            }
            
            if (!(in >> val)) break;
            if (val != "#") {
                node->right = new TreeNode(stoi(val));
                q.push(node->right);
            }
        }
        
        return root;
    }
};

// Helper function to print a tree (in-order traversal)
void printTree(TreeNode* root) {
    if (!root) return;
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

int main() {
    // Construct a sample tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Codec codec;
    string serialized = codec.serialize(root);
    cout << "Serialized tree: " << serialized << endl;
    
    TreeNode* deserializedRoot = codec.deserialize(serialized);
    cout << "Deserialized tree (in-order traversal): ";
    printTree(deserializedRoot);
    cout << endl;
    
    return 0;
}

// output
// Serialized tree: 1 2 3 # # 4 5 # # # # 
// Deserialized tree (in-order traversal): 2 1 4 3 5 