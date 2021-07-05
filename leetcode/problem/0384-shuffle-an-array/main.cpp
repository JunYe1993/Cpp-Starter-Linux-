#include<iostream>
#include<vector>
#include<cstdlib> 

using namespace std;

class Solution {
    vector<int> init;
    vector<int> cur;
    void swap (int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
public:
    Solution(vector<int>& nums) {
        init = nums;
        cur = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        cur = init;
        return cur;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        cout << 
        size_t targetIndex;
        for (size_t i = 0; i < cur.size()-1; ++i) {
            targetIndex = rand() % (cur.size()-i) + i;
            swap (cur[i], cur[targetIndex]);
        }
        return cur;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */