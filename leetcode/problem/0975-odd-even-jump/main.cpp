#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <map>

using namespace std;

class Solution {
    struct indexInfo {
        bool isOddJumpGood;
        bool isEvenJumpGood;
    };
public:
    int oddEvenJumps(vector<int>& arr) {
        
        int size = arr.size();
        vector<struct indexInfo> indexs(size, {false, false});
        map<int, int> map;
        indexs[size-1].isOddJumpGood = true;
        indexs[size-1].isEvenJumpGood = true;
        map[arr[size-1]] = size-1;
        for (int i = size - 2; i >= 0; --i) {
            auto oddjumpIt = map.lower_bound(arr[i]);
            auto evenjumpIt = map.upper_bound(arr[i]);
            if (oddjumpIt != map.end()) indexs[i].isOddJumpGood = indexs[oddjumpIt->second].isEvenJumpGood;
            if (evenjumpIt != map.begin()) indexs[i].isEvenJumpGood = indexs[(--evenjumpIt)->second].isOddJumpGood;
            map[arr[i]] = i;
        }
            
    
        int count = 0;
        int i = 0;
        for (auto&index:indexs) {
            // printf("arr[%d] : %d\n", i, arr[i]);
            // printf("Can make odd jump : %s\n", (index.isOddJumpGood)?"Yes":"No");
            // printf("Can make even jump : %s\n", (index.isEvenJumpGood)?"Yes":"No");
            if (index.isOddJumpGood) {
                ++count;
            }
            ++i;
        }
            
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> arr;

    arr = {10,13,12,14,15};
    cout << sol.oddEvenJumps(arr) << endl;
    arr = {2,3,1,1,4};
    cout << sol.oddEvenJumps(arr) << endl;
    arr = {5,1,3,4,2};
    cout << sol.oddEvenJumps(arr) << endl;
    arr = {1,1,1,1};
    cout << sol.oddEvenJumps(arr) << endl;
    arr = {1,2,3,2,1,4,4,5};
    cout << sol.oddEvenJumps(arr) << endl;

    return 0;
}