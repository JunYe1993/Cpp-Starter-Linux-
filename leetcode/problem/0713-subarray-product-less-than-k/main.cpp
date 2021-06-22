#include<iostream>
#include<string>
#include<vector>
#include<math.h>

using namespace std;

class Solution {
public:

    int numSubarrayProductLessThanK1(vector<int>& nums, int k) {
        int cur = 1, curLength = 0, answer = 0;
        
        for (size_t i = 0; i < nums.size(); ++i) {
            // cout << "*** " << i << " ***" << endl;
            cur = 1; curLength = 0;
            while (i+curLength < nums.size()) {
                cur *= nums[i+curLength];
                if (cur >= k) 
                    break;
                ++curLength;
            }
            // cout << curLength << endl;
            answer += curLength;
        }
        return answer;
    }

    int numSubarrayProductLessThanK2(vector<int>& nums, int k) {
        int cur, curLength = 0, answer = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (curLength < 2) {
                curLength = 0;
                cur = 1;
            } else {
                --curLength;
                cur = cur / nums[i-1];
            }

            while (i+curLength < nums.size()) {
                cur *= nums[i+curLength];
                if (cur >= k) {
                    cur = cur / nums[i+curLength];
                    break;
                }
                ++curLength;
            }
            answer += curLength;
        }
        return answer;
    }
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0) return 0;
        int curNum = 1, answer = 0;
        for (size_t lw = 0, rw = 0; rw < nums.size(); ++rw) {
            curNum *= nums[rw];
            while (lw <= rw && curNum >= k) {
                curNum /= nums[lw++];
            }
            answer += rw - lw + 1;
        }
        return answer;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums;
    int k;
    
    // Test1
    cout << "Test1" << endl;
    nums = {10,5,2,6}; 
    k = 100;
    cout << sol.numSubarrayProductLessThanK(nums, k) << endl;
    cout << sol.numSubarrayProductLessThanK2(nums, k) << endl;

    // Test1
    cout << "Test2" << endl;
    nums = {1,2,3}; 
    k = 0;
    cout << sol.numSubarrayProductLessThanK(nums, k) << endl;
    cout << sol.numSubarrayProductLessThanK2(nums, k) << endl;

    // Test1
    cout << "Test2" << endl;
    nums = {10,9,10,4,3,8,3,3,6,2,10,10,9,3};
    k = 19;
    cout << sol.numSubarrayProductLessThanK(nums, k) << endl;
    cout << sol.numSubarrayProductLessThanK2(nums, k) << endl;
    

    return 0;
}