#include<iostream>
#include<string>
#include<vector>
#include<map>

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
    void inOrder (TreeNode* node, vector<int>& nums) {
        if (node == nullptr) {
            nums.push_back(-101);
            return;
        } else {
            nums.push_back(node->val);
            inOrder (node->left, nums);
            inOrder (node->right, nums);
        }
    }
    void postOrder (TreeNode* node, vector<int>& nums) {
        if (node == nullptr) {
            nums.push_back(-101);
            return;
        } else {
            nums.push_back(node->val);
            postOrder (node->right, nums);
            postOrder (node->left, nums);
        }
    }
    bool isSymmetricQ(TreeNode* root) {
        vector<int> numLeft, numRight;
        inOrder(root->left, numLeft);
        postOrder(root->right, numRight);
        return numLeft == numRight;
    }

    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true; //Tree is empty
        return isSymmetricTest(root->left,root->right);
    }
    bool isSymmetricTest(TreeNode* p , TreeNode* q){
        if(p == NULL && q == NULL) //left & right node is NULL 
            return true;
        else if(p == NULL || q == NULL) //one of them is Not NULL
            return false;
        else if(p->val!=q->val) 
            return false;
        
        return isSymmetricTest(p->left,q->right) && isSymmetricTest(p->right,q->left); //comparing left subtree's left child with right subtree's right child --AND-- comparing left subtree's right child with right subtree's left child
    }
};

int main() {
    TreeNode root(1);
    TreeNode l(2);
    TreeNode r(2);
    TreeNode ll(2);
    TreeNode rl(2);
    root.left = &l;
    root.right = &r;
    l.left = &ll;
    r.left = &rl;
    Solution sol;
    sol.isSymmetric(&root);
    return 0;
}