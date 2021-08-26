#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

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
    int goodNodesCount;
    void find (TreeNode* node, int preMax) {
        if (node == nullptr) return;
        if (node->val >= preMax) ++goodNodesCount;
        preMax = max(preMax, node->val);
        find (node->left, preMax);
        find (node->right, preMax);
    }
public:
    int goodNodes (TreeNode* root) {
        goodNodesCount = 0;
        find (root, INT_MIN);
        return goodNodesCount;
    }
};

int main() {
    return 0;
}