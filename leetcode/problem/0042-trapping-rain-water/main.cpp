#include <iostream>
#include <string>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:

    // Intutive solution
    int trapQ (vector<int>& height) {
 
        // The first height in stack will be pivot.                                                                
        //
        // 1) New height >= pivot. 
        //   This mean the left side of the new height will no longer matter
        //   So calculate all the water, then clear the stack.
        //
        //             |     |                              
        //     |       |     |                               
        //     | |  +  |  =  |                                          
        //     | |     |     |
        //
        // 2) New height < pivot
        //   Keep calculating until there's a height bigger than new height
        //
        //     |             |                              
        //     |       |     | | |                              
        //     | |  +  |  =  | | |                                         
        //     | |     |     | | |
        //
        // 3) Calculating
        //   1)
        //     Answer += pivot minus cur height
        //     then clear stack.
        //   2)
        //     Answer += new height minus cur height
        //     then let cur height become new height for not double calculating.
        
        int size = height.size();
        int res = 0;
        vector<int> curTrap = {height[0]};
        for (int i = 1; i < size; ++i) {

            if (height[i] >= curTrap[0]) {
                for (int index = curTrap.size()-1; index > 0; --index)
                    res += curTrap[0] - curTrap[index];
                curTrap = {height[i]};
            } else {
                for (int index = curTrap.size()-1; index > 0; --index) {
                    if (height[i] > curTrap[index]) {
                        res += height[i]-curTrap[index];
                        curTrap[index] = height[i];
                    }
                }
                curTrap.push_back(height[i]);
            }
        }

        return res;
    }

    // Intutive solution with little math 
    int trap (vector<int>& height) {
        
        int size = height.size();
        int res = 0;
        vector<pair<int, int>> curTrap = {{height[0], 1}};
        
        for (int i = 1; i < size; ++i) {
            // cout << i << endl;
            if (height[i] >= curTrap[0].first) {
                for (auto&h:curTrap) 
                    res += (curTrap[0].first - h.first) * h.second;
                curTrap = {{height[i], 1}};
            } else {
                int count = 0;
                while (height[i] > curTrap.back().first) {
                    res += (height[i] - curTrap.back().first) * curTrap.back().second;
                    count += curTrap.back().second;
                    curTrap.pop_back();
                }
                curTrap.push_back({height[i], count+1});
            }
        }

        return res;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> height;
    
    height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << sol.trap(height) << endl;
    height = {4,2,0,3,2,5};
    cout << sol.trap(height) << endl;

    return 0;
}