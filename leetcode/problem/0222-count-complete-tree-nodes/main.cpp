#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <math.h>

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

// 正統 BST 作法, 沒比較快
class Solution {
    bool isExist (TreeNode* node, int pivot, int depth) {
        
        if (depth == 1) return node;
        int t = pow(2, depth-2);
        
        if (pivot < t) return isExist(node->left, pivot, depth-1);
        else return isExist(node->right, pivot-t, depth-1);
    }

public:
    int countNodes (TreeNode* root) {
        
        if (root == nullptr) return 0;
        
        struct TreeNode * node = root;
        int depth = 0;
        while (node) {
            ++depth;
            node = node->left;
        }
        if (depth == 0) return 1;

        int l = 0;
        int r = pow(2, depth-1) - 1;
        int pivot;
        while (l <= r) {
            pivot = (l + r) / 2;
            if (isExist(root, pivot, depth)) l = pivot + 1;
            else r = pivot - 1;
        }

        cout << l << endl;
        return pow(2, depth-1) + l - 1;
    }
};

class SolutionQ {
    bool countNodes (TreeNode* node, int level, int& count, int targetLevel) {
        
        if (!node) return false;
        
        if (level == targetLevel) {
            ++count;
            return true;
        } 
        else
            return countNodes(node->left, level+1, count, targetLevel) &&
                    countNodes(node->right, level+1, count, targetLevel);
    }

public:
    int countNodes (TreeNode* root) {
        
        if (root == nullptr) return 0;
        
        struct TreeNode * node = root;
        int targetLevel = 0;
        while (node) {
            ++targetLevel;
            node = node->left;
        }

        int res = 0;
        countNodes(root, 1, res, targetLevel);        
        return res + pow(2, targetLevel-1) - 1;
    }
};

int main() {

    Solution sol;
    struct TreeNode root(0);
    struct TreeNode l(0);
    struct TreeNode r(0);
    struct TreeNode ll(0);
    struct TreeNode lr(0);
    struct TreeNode rl(0);

    root.left  = &l;
    root.right = &r;
    l.left  = &ll;
    l.right = &lr;
    r.left  = &rl;

    cout << sol.countNodes(&root) << endl;

    return 0;
}