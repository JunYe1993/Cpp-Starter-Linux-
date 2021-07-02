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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    bool getAncestors (TreeNode* node, TreeNode* target, vector<TreeNode*>& list) {
        if (node == nullptr) return false;
        if (node == target) {
            list.push_back(node);
            return true;
        }
        
        bool hasDescendants = 
        getAncestors(node->left, target, list) ||
        getAncestors(node->right, target, list);
        
        if (hasDescendants) list.push_back(node);
        return hasDescendants;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> plist, qlist;
        getAncestors (root, p, plist);
        getAncestors (root, q, qlist);
        int pIndex = plist.size()-1;
        int qIndex = qlist.size()-1;
        TreeNode* ret;
        while (pIndex >= 0 && qIndex >= 0) {
            if (plist[pIndex] == qlist[qIndex]) {
                ret = plist[pIndex];
                --pIndex;
                --qIndex;
            } else break;
        }
        return ret;
    }
};

int main() {
    Solution sol;
    TreeNode root = TreeNode(3);
    TreeNode l = TreeNode(5);
    TreeNode r = TreeNode(1);
    TreeNode ll = TreeNode(6);
    TreeNode lr = TreeNode(2);
    TreeNode rl = TreeNode(0);
    TreeNode rr = TreeNode(8);
    TreeNode lrl = TreeNode(7);
    TreeNode lrr = TreeNode(4);
    root.left = &l;
    root.right = &r;
    l.left = &ll;
    l.right = &lr;
    r.left = &rl;
    r.right = &rr;
    lr.left = &lrl;
    lr.right = &lrr;
    cout << sol.lowestCommonAncestor(&root, &l, &r)->val << endl;

    return 0;
}