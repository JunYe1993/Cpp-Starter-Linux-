#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <climits>

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
    
    int getMaxPathSum (TreeNode* node, int& maxSum) {

        if (!node) return 0;
        int left  = getMaxPathSum (node->left,  maxSum);
        int right = getMaxPathSum (node->right, maxSum);
        int subMax = max(node->val, max(left, right)+node->val);
        maxSum = max({maxSum, left+right+node->val, subMax});
        return subMax;
    }

public:

    int maxPathSum (TreeNode* root) {
        
        int maxSum = INT_MIN;
        getMaxPathSum (root, maxSum);
        return maxSum;
    }
};

int main() {
    Solution sol;
    TreeNode root = TreeNode(-10);
    TreeNode l = TreeNode(9);
    TreeNode r = TreeNode(20);
    TreeNode rl = TreeNode(15);
    TreeNode rr = TreeNode(7);
    root.left  = &l;
    root.right = &r;
    r.left  = &rl;
    r.right = &rr;

    cout << sol.maxPathSum(&root) << endl;
    return 0;
}