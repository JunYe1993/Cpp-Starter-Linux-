#include <iostream>
#include <string>
#include <vector>
#include <queue>

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
    int sumNumbers (TreeNode* node, int sum) {
        if (!node) return 0;
        sum = sum * 10 + node->val;
        if (!node->left && !node->right) return sum;
        return sumNumbers(node->left, sum) + sumNumbers(node->right, sum);
    }

public:
    int sumNumbers (TreeNode* root) {
        return sumNumbers(root, 0);
    }
};

int main() {

    Solution sol;
    TreeNode root(1);
    TreeNode l(2);
    TreeNode r(3);
    root.left  = &l;
    root.right = &r;
    cout << sol.sumNumbers(&root) << endl;

    return 0;
}