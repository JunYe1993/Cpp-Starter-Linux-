#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canReach (vector<int>& arr, int start) {
        
        int size = arr.size();
        bool valid = false;

        for (int i = 0; i < size; ++i) 
            if (arr[i] == 0)
                valid = true;
        if (!valid) return valid;

        vector<int> queue = {start};
        int cur_size  = 0;
        int next_size = queue.size();
        while (cur_size != next_size) {
            for (int i = next_size-1; i >= cur_size; --i) {
                int index = queue[i];
                if (arr[index] < 0) continue;
                if (arr[index] == 0) return true;
                int move_forward  = index + arr[index];
                int move_backward = index - arr[index];
                if (move_forward < size && arr[move_forward]  >= 0) queue.push_back(move_forward);
                if (move_backward >= 0  && arr[move_backward] >= 0) queue.push_back(move_backward);
                arr[index] *= -1;
            }
            cur_size = next_size;
            next_size = queue.size();
        }

        return false;
    }
};

int main() {
    Solution sol;
    vector<int> arr;
    int start;

    arr = {4,2,3,0,3,1,2};
    start = 5;
    printf("%s\n", (sol.canReach(arr, start))?"True":"False");
    arr = {4,2,3,0,3,1,2};
    start = 0;
    printf("%s\n", (sol.canReach(arr, start))?"True":"False");
    arr = {3,0,2,1,2};
    start = 2;
    printf("%s\n", (sol.canReach(arr, start))?"True":"False");


    return 0;
}