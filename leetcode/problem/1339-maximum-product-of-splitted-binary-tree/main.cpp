#include <iostream>
#include <algorithm>
#include <vector>
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

    vector<long int> sums;
    int getTreeSum (TreeNode* node) {
        if (node == nullptr) return 0;
        int sum = node->val + getTreeSum(node->left) + getTreeSum(node->right);
        sums.push_back(sum);
        return sum;
    }

public:
    int maxProduct(TreeNode* root) {
        long int sum = getTreeSum (root);
        long int target = sum/2;
        long int minGap = sum;
        for (long int&s:sums) {
            if (abs(minGap) > abs(s-target))
                minGap = s-target;
        }
        // int answer = 
        return (int)(((target+minGap)*(sum-target-minGap))%1000000007);
    }
};

int main() {
    Solution sol;
    TreeNode root(1);
    TreeNode l(2);
    TreeNode r(3);
    TreeNode ll(4);
    TreeNode lr(5);
    TreeNode rl(6);
    root.left = &l;
    root.right = &r;
    l.left = &ll;
    l.right = &lr;
    r.left = &rl;

    cout << sol.maxProduct(&root) << endl;

    return 0;
}