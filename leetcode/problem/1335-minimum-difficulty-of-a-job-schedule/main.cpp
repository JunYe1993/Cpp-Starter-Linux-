#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

class Solution {
    vector<vector<int>> dp;
    int size;

public:
    int dfs (vector<int>& jobs, int index, int count) {

        if (count == 0) return 0;

        if (dp[index][count] != -1) {
            return dp[index][count];
        }
        // string str = "                                         ";
        // str.resize((8-count)*3);
        if (count == 1) {
            int ret = 0;
            for (int i = index; i < size; ++i)
                ret = max(ret, jobs[i]);
            // printf("%scurRetM : %d\n", str.c_str(), ret);
            dp[index][count] = ret;
            return ret;
        }

        int rest_size = size - count + 1;
        int curMaxD = 0;
        int curRetM = 2147483647;
        for (int i = index; i < rest_size; ++i) {
            curMaxD = max(curMaxD, jobs[i]);
            // printf("%sindex   : %d\n", str.c_str(), i);
            // printf("%scurMaxD : %d\n", str.c_str(), curMaxD);
            int tmp = curMaxD + dfs(jobs, i+1, count-1);
            curRetM = min(curRetM, tmp);
            // printf("%scurRetM : %d\n", str.c_str(), curRetM);
        }

        dp[index][count] = curRetM;
        return curRetM;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        size = (int)jobDifficulty.size();
        if (d > size) return -1;
        dp = vector<vector<int>>(size, vector<int>(d+1, -1));
        return dfs(jobDifficulty, 0, d);
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    nums = {6,5,4,3,2,1};
    cout << sol.minDifficulty(nums, 2) << endl;
    nums = {9,9,9};
    cout << sol.minDifficulty(nums, 4) << endl;
    nums = {1,1,1};
    cout << sol.minDifficulty(nums, 3) << endl;
    nums = {11,111,22,222,33,333,44,444};
    cout << sol.minDifficulty(nums, 6) << endl;
    nums = {380,302,102,681,863,676,243,671,651,612,162,561,394,856,601,30,6,257,921,405,716,126,158,476,889,699,668,930,139,164,641,801,480,756,797,915,275,709,161,358,461,938,914,557,121,964,315};
    cout << sol.minDifficulty(nums, 10) << endl;

    return 0;
}