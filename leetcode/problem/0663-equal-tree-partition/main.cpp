#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

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

    unordered_map<int, int> sums;
    int getSum (TreeNode* node) {
        if (node == nullptr) return 0;
        int sum = node->val + getSum(node->left) + getSum(node->right);
        if (sums.find(sum) == sums.end()) sums[sum] = 1;
        else ++sums[sum];
        return sum;
    }

public:
    bool checkEqualTree (TreeNode* root) {
        int sum = getSum(root);
        if (sum%2) return false;
        --sums[sum];
        return (sums.find(sum/2)!=sums.end() && sums[sum/2] > 0);
    }
};

int main() {
    return 0;
}