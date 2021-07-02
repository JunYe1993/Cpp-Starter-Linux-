#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> mockSet;
    int find (int x) {
        return mockSet[x] == x ? x : find(mockSet[x]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // 模擬所有 set，初始各自是一個 set
        mockSet.resize(edges.size()+1);
        for (size_t i = 1; i < edges.size()+1; ++i) mockSet[i] = i;
        
        for (auto& edge : edges) { 
            // 找串接最高的點
            int num1 = find(edge[0]);
            int num2 = find(edge[1]);

            // 串到最高時若一樣，同一set
            if (num1 == num2) return edge;
            // 左邊串到右邊，題目有訂 a < b
            else mockSet[num1] = num2;
        }
        return {};
    }
    
    // 直觀 set 想法，但效率低落。
    vector<int> findRedundantConnectionQ(vector<vector<int>>& edges) {
        vector<set<int>> sets;
        for (auto& edge : edges) {
            auto left  = sets.end();
            auto right = sets.end();
            
            // search in sets
            for (size_t i = 0; i < sets.size(); ++i) {
                if (left != sets.end() && right != sets.end()) break;
                if (sets[i].find(edge[0]) != sets[i].end()) left  = sets.begin()+i;
                if (sets[i].find(edge[1]) != sets[i].end()) right = sets.begin()+i;
            }

            if (left == sets.end() && right == sets.end())
                sets.push_back(set<int>{edge[0], edge[1]});
            else if (left == sets.end() && right != sets.end())
                right->insert(edge[0]);
            else if (left != sets.end() && right == sets.end())
                left->insert(edge[1]);
            else if (left == right)
                return edge;
            else if (left != right) {
                left->insert(right->begin(), right->end());
                sets.erase(right);
            }
        }
        return {0, 0};
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges;
    vector<int> ret;

    edges = {{1, 2}, {1, 3}, {2, 3}};
    ret = sol.findRedundantConnection(edges);
    cout << ret[0] << ", " << ret[1] << endl;

    edges = {{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}};
    ret = sol.findRedundantConnection(edges);
    cout << ret[0] << ", " << ret[1] << endl;

    edges = {{3, 4}, {1, 2}, {2, 4}, {3, 5}, {2, 5}};
    ret = sol.findRedundantConnection(edges);
    cout << ret[0] << ", " << ret[1] << endl;

    return 0;
}