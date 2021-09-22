#include <iostream>
#include <vector>

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
    struct nodes {
        double number;
        double sum;
        nodes(): number(0), sum(0) {}
    };
    
    double maxAverage;
    struct nodes findAverage (TreeNode* node) {
        struct nodes thisNode;
        if (node == nullptr) return thisNode;
        struct nodes left  = findAverage(node->left);
        struct nodes right = findAverage(node->right);
        thisNode.number = left.number + right.number + 1;
        thisNode.sum = left.sum + right.sum + node->val;
        double averge = thisNode.sum / thisNode.number;
        // printf("left  : number = %lf, sum = %lf\n", left.number, left.sum);
        // printf("right : number = %lf, sum = %lf\n", right.number, right.sum);
        // printf("Average = %lf\n\n", averge);
        maxAverage = max(maxAverage, averge);
        return thisNode;
    }

public:
    double maximumAverageSubtree (TreeNode* root) {
        maxAverage = 0;
        findAverage(root);
        return maxAverage;
    }
};

int main() {
    Solution sol;
    TreeNode root(2);
    TreeNode r(1);
    root.right = &r;

    cout << sol.maximumAverageSubtree(&root) << endl;

    return 0;
}