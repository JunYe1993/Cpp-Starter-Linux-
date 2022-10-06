#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
#include <bitset>         // std::bitset

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
    int travel (TreeNode* node, bitset<9>& stat) {
        
        int ret = 0;
        
        stat.flip(node->val-1);
        if (!node->left && !node->right)
            ret = (stat.count() < 2) ? 1 : 0;
        else {
            if(node->left)  ret += travel(node->left,  stat);
            if(node->right) ret += travel(node->right, stat);
        }
        stat.flip(node->val-1);

        return ret;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        if (root == nullptr) return 0;
        bitset<9> stat;
        stat.reset();
        return travel(root, stat);
    }
};

int main() {
    Solution sol;
    // [2,3,1,3,1,null,1]
    TreeNode root = TreeNode(2);
    TreeNode l = TreeNode(3);
    TreeNode r = TreeNode(1);
    TreeNode ll = TreeNode(3);
    TreeNode lr = TreeNode(1);
    TreeNode rr = TreeNode(1);
    root.left  = &l;
    root.right = &r;
    l.left  = &ll;
    l.right = &lr;
    r.right = &rr;
    cout << sol.pseudoPalindromicPaths(&root) << endl;

    return 0;
}