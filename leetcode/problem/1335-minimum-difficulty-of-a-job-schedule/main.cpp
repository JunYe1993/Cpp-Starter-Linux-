#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

class Solution {
    vector<vector<int>> dp;
    void show() {
        for(auto&v:dp){
            for(auto&n:v)
                printf("%d ", n);
            printf("\n");
        }
        printf("\n");
        printf("\n");
    }
public:
    int dfs (vector<int>& jobs, int index, int count) {

        if (count == 0) return 0;
        if (dp[index][count] != -1) {
            return dp[index][count];
        }

        int left = (int)jobs.size() - count + 1;
        int curDayMax = 0;
        int curRunMin = 2147483647;
        string str = "                                          ";
        str.resize((8-count)*4);
        printf("%sleft = %d\n", str.c_str(), left);
        for (int i = index; i < left; ++i) {
            printf("%si = %d\n", str.c_str(), i);
            curDayMax = max(curDayMax, jobs[i]);
            int ret = curDayMax+dfs(jobs, i+1, count-1);
            printf("%ssum = %d\n", str.c_str(), ret);
            curRunMin = min(curRunMin, ret);
        }
        printf("%scurRunMin = %d\n", str.c_str(), curRunMin);
        dp[index][count] = curRunMin;
        show();
        return curRunMin;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if ((int)jobDifficulty.size() < d)
            return -1;

        dp = vector<vector<int>>( (int)jobDifficulty.size() , vector<int> (d+1, -1));
        int answer = dfs(jobDifficulty, 0, d);
        show();
        return answer;
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    // nums = {6,5,4,3,2,1};
    // cout << sol.minDifficulty(nums, 2) << endl;
//
    // nums = {9,9,9};
    // cout << sol.minDifficulty(nums, 4) << endl;
//
    // nums = {1,1,1};
    // cout << sol.minDifficulty(nums, 3) << endl;

    nums = {11,111,22,222,33,333,44,444};
    cout << sol.minDifficulty(nums, 6) << endl;

    return 0;
}