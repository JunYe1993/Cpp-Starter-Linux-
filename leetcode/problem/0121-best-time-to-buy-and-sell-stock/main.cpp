#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int length = prices.size();
        int _maxProfit = 0;
        int preLowest = prices[0];
        for (int i = 1; i < length; ++i) {
            int curProfit = prices[i] - preLowest;
            _maxProfit = (_maxProfit > curProfit) ? _maxProfit : curProfit;
            preLowest = (preLowest < prices[i]) ? preLowest : prices[i];
        }
        return _maxProfit;
    }
};

int main() {
    Solution sol;
    vector<int> prices;
    
    prices = {7, 1, 5, 3, 6, 4};
    cout << sol.maxProfit(prices) << endl;

    prices = {7, 6, 4, 3, 1};
    cout << sol.maxProfit(prices) << endl;

    return 0;
}