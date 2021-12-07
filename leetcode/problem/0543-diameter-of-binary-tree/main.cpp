#include <iostream>
#include <vector>
#include <string> 
#include <cctype>

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
    int longestPath (TreeNode* node, int& path) {
        if (!node) return 0;
        int l = longestPath(node->left,  path);
        int r = longestPath(node->right, path);
        path = max (path, l + r);
        return max(l, r) + 1;
    }
public:
    int diameterOfBinaryTree (TreeNode* root) {
        int path = 0;
        longestPath(root, path);
        return path;
    }
};

int main () {

    return 0;
}