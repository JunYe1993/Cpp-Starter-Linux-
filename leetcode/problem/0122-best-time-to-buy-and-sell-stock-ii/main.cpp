#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int profit = 0;
        for (size_t i = 0; i < prices.size()-1; ++i) {
            prices[i] = prices[i+1] - prices[i];
            if (prices[i] > 0)
                profit += prices[i];
        }
        return profit;
    }
};

int main() {
    Solution sol = Solution();
    
    // Test1
    vector<int> nums = {7,1,5,3,6,4};
    int answer = sol.maxProfit(nums);
    cout << answer << endl;
    for (auto&n:nums)
        cout << n << " ";
    cout << endl;

    return 0;
}