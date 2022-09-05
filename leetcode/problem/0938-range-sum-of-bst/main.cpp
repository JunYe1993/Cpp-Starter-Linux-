#include <iostream>
#include <string>
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
public:
    int rangeSumBST (TreeNode* root, int low, int high) {
        
        if (root == nullptr) return 0;
        
        int ret = 0;
        bool l, r;
        
        if ((l = (root->val >= low ))) ret += rangeSumBST(root->left, low, high);
        if ((r = (root->val <= high))) ret += rangeSumBST(root->right, low, high);
        if (l & r) ret += root->val;
        return ret;
    }
};

int main() {
    return 0;
}