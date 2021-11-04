#include <iostream>
#include <string>
#include <map>

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
    int sumOfLeftLeaves (TreeNode* node, bool isLeft) {
        if (!node) return 0;
        if (!node->left && !node->right && isLeft) return node->val;
        return sumOfLeftLeaves(node->left, true) + sumOfLeftLeaves(node->right, false);
    }

public:
    int sumOfLeftLeaves (TreeNode* root) {
        return sumOfLeftLeaves (root, false);
    }
};

int main() {
    Solution sol = Solution();
    // TreeNode root(3);
    // TreeNode l(9);
    // TreeNode r(20);
    // TreeNode rl(15);
    // TreeNode rr(7);
    // root.left  = &l;
    // root.right = &r;
    // r.left  = &rl;
    // r.right = &rr;
    TreeNode root(1);
    cout << sol.sumOfLeftLeaves(&root) << endl;

    return 0;
}