#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_set>

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

    void printLog (vector<vector<int>>& vs) {
        for (auto&v:vs) {
            for (auto&n:v) 
                cout << n << " ";
            cout << endl;
        }
        cout << endl;
    }

    vector<vector<int>> get_orders (int begin, int end) {
       
        // begin > end 還是要回傳 size 為 1 的空陣列
        if (begin > end) return {{}};
        
        vector<vector<int>> ret;
        for (int i = begin; i <= end; ++i) {

            // 取左邊組合 跟 右邊組合
            auto left_orders  = get_orders (begin, i-1);
            auto right_orders = get_orders (i+1, end);

            // 組合
            for (auto&l:left_orders) {
                for (auto&r:right_orders) {
                    ret.push_back({i});
                    ret.back().insert(ret.back().end(), l.begin(), l.end());
                    ret.back().insert(ret.back().end(), r.begin(), r.end());
                }
            }
        }

        return ret;
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        
        vector<TreeNode*> ret;
        vector<vector<int>> orders = get_orders(1, n);
        
        if (orders.back().empty()) return ret;
        
        for (auto & v : orders) {
            ret.push_back(nullptr);
            for (auto & n : v) {
                TreeNode **cur = &(ret.back());
                while (*cur) {
                    cur = (n <= (*cur)->val) ? &((*cur)->left) : &((*cur)->right);
                }
                *cur = new TreeNode(n);
            }
        }

        return ret;
    }
};

int main() {
    Solution sol;
    // sol.generateTrees(1);
    // sol.generateTrees(2);
    sol.generateTrees(3);
    // sol.generateTrees(4);
    return 0;
}