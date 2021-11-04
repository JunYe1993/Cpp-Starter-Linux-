#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {

    void swap (vector<int>::iterator a, vector<int>::iterator b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

public:
    vector<int> sortArrayByParityII (vector<int>& nums) {
        
        queue<int> even, odd;
        for (size_t i = 0; i < nums.size(); ++i) {
            if ((int)i % 2 != nums[i] % 2) {
                if (i % 2 == 0) {
                    if (!odd.empty()) {
                        int t = odd.front();
                        swap (nums.begin()+i, nums.begin()+t);
                        odd.pop();
                    } else {
                        even.push(i);
                    }
                } else {
                    if (!even.empty()) {
                        int t = even.front();
                        swap (nums.begin()+i, nums.begin()+t);
                        even.pop();
                    } else {
                        odd.push(i);
                    }
                }
            }
        }

        return nums;
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    nums = {4,2,5,7};
    for (auto&n:sol.sortArrayByParityII(nums))
        cout << n << " ";
    cout << endl;
    nums = {2,3};
    for (auto&n:sol.sortArrayByParityII(nums))
        cout << n << " ";
    cout << endl;
    
    return 0;
}