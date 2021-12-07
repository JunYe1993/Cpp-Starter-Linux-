#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;


class Solution {
public:
    
    vector<int> findDisappearedNumbers (vector<int>& nums) {
        
        int size = nums.size();
        vector<int> res;
        
        // 把該 index 的 num 變負數代表有出現
        // Ex 
        //  4, 3, 2, 7, 8, 2, 3, 1 
        //  4, 3, 2,-7, 8, 2, 3, 1 ( 4 -> nums[3] = -nums[3] )
        //  4, 3,-2,-7, 8, 2, 3, 1 ( 3 -> nums[2] = -nums[2] )
        //  4,-3,-2,-7, 8, 2, 3, 1 (-2 -> nums[1] = -nums[1] )
        //  4,-3,-2,-7, 8, 2, 3, 1 (-7 -> nums[6] = -nums[6] )
        //  4,-3,-2,-7, 8, 2,-3,-1 ( 8 -> nums[7] = -nums[7] )
        //  4,-3,-2,-7, 8, 2,-3,-1 ( 2 -> nums[1] no change  )
        //  4,-3,-2,-7, 8, 2,-3,-1 (-3 -> nums[2] no change  )
        // -4,-3,-2,-7, 8, 2,-3,-1 ( 1 -> nums[0] = -nums[0] )
        // 只有 index = 4, 5 沒變負數 (答案:[5, 6])

        for (int i = 0; i < size; ++i) {
            int index = abs(nums[i]) - 1;
            if (nums[index] > 0) 
                nums[index] = nums[index] * (-1);
        }

        for (int i = 0; i < size; ++i)
            if (nums[i] > 0)
                res.push_back(i+1);
        
        return res;
    }


    vector<int> findDisappearedNumbersQ (vector<int>& nums) {
        
        int size = nums.size();
        vector<int> missMap (size, 0);
        vector<int> res;
        
        for (auto&n:nums) 
            ++missMap[n-1];
        for (int i = 0; i < size; ++i)
            if (missMap[i] == 0)
                res.push_back(i+1);
        
        return res;
    }
};

int main () {
    Solution sol;
    vector<int> nums;

    nums = {4,3,2,7,8,2,3,1};
    for (auto&n:sol.findDisappearedNumbers(nums))
        cout << n << " ";
    cout << endl;
    nums = {1,1};
    for (auto&n:sol.findDisappearedNumbers(nums))
        cout << n << " ";
    cout << endl;

    return 0;
}