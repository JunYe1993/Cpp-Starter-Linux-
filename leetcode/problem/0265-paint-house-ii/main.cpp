#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class Solution {
    int n, k;
    vector<vector<int>> dp;
    int getCost (vector<vector<int>>& costs, int layer, int preIndex) {
        
        if (layer == n) return 0;
        
        if (dp[layer][preIndex] > 0)
            return dp[layer][preIndex];

        int minNum = INT_MAX;
        for (int i = 0; i < k; ++i) 
            if (i != preIndex)
                minNum = min(minNum, costs[layer][i] + getCost(costs, layer+1, i));

        dp[layer][preIndex] = minNum;
        return minNum;
    }
public:
    int minCostII (vector<vector<int>>& costs) {
        int minCost = INT_MAX;
        n = costs.size();
        k = costs[0].size();
        dp = vector<vector<int>>(n, vector<int>(k, -1));
        for (int i = 0; i < k; ++i) {
            // printf("Cost[0][%2d ] = %2d, getCost = %2d\n", i, costs[0][i], getCost(costs, 1, i));
            minCost = min(minCost, getCost(costs, 1, i) + costs[0][i]);
        }
        
        return minCost;
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> costs;
    
    costs = {{1,5,3}, {2,9,4}};
    cout << sol.minCostII(costs) << endl;
    costs = {{1,3}, {2,4}};
    cout << sol.minCostII(costs) << endl;

    return 0;
}