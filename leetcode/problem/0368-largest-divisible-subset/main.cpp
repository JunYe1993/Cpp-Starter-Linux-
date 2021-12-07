#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class Solution {
    
    int DFS (vector<int>& nums, vector<vector<int>>& dp, int index, vector<int>& res) {

        if (!dp[index].empty()) return (int)(dp[index].size());
        
        dp[index].push_back(nums[index]);
        int subIndex = -1;
        int maxSubSize = 0;
        for (int i = index+1; i < (int)nums.size(); ++i) {
            if (nums[i] % nums[index] == 0) {
                int subSize = DFS (nums, dp, i, res);
                if (subSize > maxSubSize) {
                    maxSubSize = subSize;
                    subIndex = i;
                }
            }
        }
        
        if (subIndex > 0) dp[index].insert(dp[index].end(), dp[subIndex].begin(), dp[subIndex].end());  
        if (res.size() < dp[index].size()) res = dp[index];
        // printf("CurIndex = %2d\n", index);
        // printf("SubIndex = %2d\n", subIndex);
        // show (dp);
        // cout << "------------\n";
        return (int)(dp[index].size());
    }

    void show (vector<vector<int>>& m) {
        int raw = 0;
        for (auto&v:m) {
            printf("%2d : ", raw++);
            for (auto&n:v)
                cout << n << " ";
            cout << endl;
        }
    }

public:
    vector<int> largestDivisibleSubset (vector<int>& nums) {
        
        int size = nums.size();
        vector<vector<int>> dp(size, vector<int>());
        vector<int> res;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < size; ++i) 
            if (dp[i].empty())
                DFS (nums, dp, i, res);

        return res;

    }
};

int main() {

    Solution sol = Solution();
    vector<int> nums;

    nums = {1,2,3};
    for (auto&n:sol.largestDivisibleSubset(nums))
        cout << n << " ";
    cout << endl;
    nums = {1,2,4,8};
    for (auto&n:sol.largestDivisibleSubset(nums))
        cout << n << " ";
    cout << endl;
    nums = {1};
    for (auto&n:sol.largestDivisibleSubset(nums))
        cout << n << " ";
    cout << endl;
    nums = {5,9,18,54,108,540,90,180,360,720};
    for (auto&n:sol.largestDivisibleSubset(nums))
        cout << n << " ";
    cout << endl;

    return 0;
}