#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

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

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int size = preorder.size();
        TreeNode* root = new TreeNode(preorder[0]);
        vector<TreeNode*> stack = {root};
        for (int i = 1; i < size; ++i) {
            TreeNode* node = new TreeNode(preorder[i]);
            if (preorder[i] < stack.back()->val) {
                stack.back()->left = node;
                stack.push_back(node);
            } else {
                TreeNode* tempNode;
                while (!stack.empty()) {
                    tempNode = stack.back();
                    stack.pop_back();
                    if (!stack.empty() && stack.back()->val > preorder[i]) break;
                }
                tempNode->right = node;
                stack.push_back(node);
            }
        }

        return root;
    }

    /* 遞迴作法

    TreeNode* bstFromPreorder(vector<int>& A) {
        int i = 0;
        return build(A, i, INT_MAX);
    }

    TreeNode* build(vector<int>& A, int& i, int bound) {
        if (i == A.size() || A[i] > bound) return NULL;
        TreeNode* root = new TreeNode(A[i++]);
        root->left = build(A, i, root->val);
        root->right = build(A, i, bound);
        return root;
    }
    
    */
};

int main() {
    return 0;
}