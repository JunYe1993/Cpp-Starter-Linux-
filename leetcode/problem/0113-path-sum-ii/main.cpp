#include <iostream>
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

    void find (TreeNode* node, int target, vector<int> cur, vector<vector<int>>& ans) {
        if (node != nullptr) {
            cur.push_back(node->val);
            target = target - node->val;
            if (node->left == nullptr && node->right == nullptr && target == 0) 
                ans.push_back(cur);
            else {
                find (node->left, target, cur, ans);
                find (node->right, target, cur, ans);
            }
        }
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> cur;
        find (root, targetSum, cur, ans);
        return ans;
    }   
};

int main() {
    Solution sol;

    TreeNode root = TreeNode(5);
    TreeNode l = TreeNode(4);
    TreeNode r = TreeNode(8);
    TreeNode ll = TreeNode(11);
    TreeNode rl = TreeNode(13);
    TreeNode rr = TreeNode(4);
    TreeNode lll = TreeNode(7);
    TreeNode llr = TreeNode(2);
    TreeNode rrl = TreeNode(5);
    TreeNode rrr = TreeNode(1);
    root.left = &l;
    root.right = &r;
    l.left = &ll;
    r.left = &rl;
    r.right = &rr;
    ll.left = &lll;
    ll.right = &llr;
    rr.left = &rrl;
    rr.right = &rrr;

    for (auto&v:sol.pathSum(&root, 22)) {
        for (auto&n:v)
            cout << n << " ";
        cout << endl;
    }
    
    return 0;
}