#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>

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
    void travel (TreeNode* node, vector<vector<int>>&nums, size_t level) {
        if (node == nullptr) return;
        if (!(level < nums.size()))
            nums.push_back(vector<int>());
        nums[level].push_back(node->val);
        travel (node->left, nums, level+1);
        travel (node->right, nums, level+1);
    }
    vector<vector<int>> levelOrderQ(TreeNode* root) {
        vector<vector<int>> nums;
        travel (root, nums, 0);
        return nums;    
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> nums;
        if (root == nullptr) return nums;
        queue<TreeNode*> q;
        
        q.push(root);
        while (!q.empty()) {
            queue<TreeNode*> temp;
            vector<int> row;
            while (!q.empty()) {
                TreeNode* cur = q.front();
                q.pop();
                row.push_back(cur->val);
                if (cur->left) temp.push(cur->left);
                if (cur->right) temp.push(cur->right);
            }
            nums.push_back(row);
            q = temp;
        }
        return nums;    
    }

};

int main() {
    TreeNode root(3);
    TreeNode l(9);
    TreeNode r(20);
    TreeNode rl(15);
    TreeNode rr(7);
    root.left = &l;
    root.right = &r;
    r.left = &rl;
    r.right = &rr;
    Solution sol;
    sol.levelOrder(&root);
    return 0;
}