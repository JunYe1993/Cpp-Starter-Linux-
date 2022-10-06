#include <iostream>
#include <vector>
#include <math.h>

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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (root == nullptr)
            return nullptr;

        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        if (depth == 2) {
            TreeNode* newLeft  = new TreeNode(val, root->left, nullptr);
            TreeNode* newRight = new TreeNode(val, nullptr, root->right);
            root->left  = newLeft;
            root->right = newRight;
            return root;
        }

        addOneRow(root->left,  val, depth-1);
        addOneRow(root->right, val, depth-1);
        return root;
    }
};

int main() {
    return 0;
}