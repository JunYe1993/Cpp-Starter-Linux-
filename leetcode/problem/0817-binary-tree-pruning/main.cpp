#include <iostream>
#include <vector>
#include <string> 

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool prune(TreeNode* node) {
        
        bool ret = (node->val == 0) ? false : true;
        
        if (node->left) {
            if (prune(node->left))
                ret = true;
            else
                node->left = nullptr;
        }
        if (node->right) {
            if (prune(node->right))
                ret = true;
            else
                node->right = nullptr;
        }
        
        return ret;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        if (prune(root))
            return root;
        else
            return nullptr;
    }
};

int main () {
    return 0;
}