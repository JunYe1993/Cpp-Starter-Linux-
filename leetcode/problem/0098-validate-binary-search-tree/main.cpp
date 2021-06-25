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
    bool travel (TreeNode* node, int cur) {
        if (node == nullptr)
            return;
        travel (node->left, nums);
        nums.push_back(node->val);
        travel (node->right, nums);
    }
public:
    bool isValidBST (TreeNode* root) {
        if (root == nullptr) 
            return true;
        vector<int> nums;
        travel (root, nums);
        for(size_t i = 0; i < nums.size(); ++i)
            if (i != 0 && nums[i] <= nums[i-1])
                return false;
        return true;
    }
};

int main() {

    return 0;
}