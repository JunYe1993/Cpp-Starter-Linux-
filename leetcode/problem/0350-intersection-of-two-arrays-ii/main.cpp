#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return intersectSub(nums2, nums1);
        else
            return intersectSub(nums1, nums2);
    }
    vector<int> intersectSub(vector<int>& nums1, vector<int>& nums2) {
        vector<int> answer;
        map<int, int> dict;
        
        for (auto&n:nums1) {
            if (dict.find(n) == dict.end())
                dict[n] = 1;
            else
                ++dict[n];
        }

        for (auto&n:nums2)
            if (dict.find(n) != dict.end() && dict[n] > 0) {
                answer.push_back(n);
                --dict[n];
            }
        
        return answer;
    }
};

int main() {

    Solution sol = Solution();
    
    // Test1
    vector<int> nums1 = {4,9,5};
    vector<int> nums2 = {9,4,9,8,4};
    for (int& n : sol.intersect(nums1, nums2))
        cout << n << " ";
    cout << endl;

    // Test2
    nums1 = {1,2,2,1};
    nums2 = {2,2};
    for (int& n : sol.intersect(nums1, nums2))
        cout << n << " ";
    cout << endl;

    return 0;
}