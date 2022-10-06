#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {

public:
    int maxDistance (vector<vector<int>>& arrays) {

        int answer = 0;
        int cur_min = arrays[0][0];
        int cur_max = arrays[0].back();
        bool min_max_same_arr = true;

        for (size_t i = 1; i < arrays.size(); ++i) {

            cout << "answer : " << answer << endl;
            cout << "cur_min : " << cur_min << endl;
            cout << "cur_max : " << cur_max << endl << endl;

            if (min_max_same_arr) {

                answer = max(answer, max(abs(arrays[i][0]-cur_max), abs(arrays[i].back()-cur_min)));

                if (cur_min > arrays[i][0]) {
                    min_max_same_arr = !min_max_same_arr;
                    cur_min = arrays[i][0];
                }
                if (cur_max < arrays[i].back()) {
                    min_max_same_arr = !min_max_same_arr;
                    cur_max = arrays[i].back();
                }

            } else {

                if (cur_min <= arrays[i][0] && cur_max >= arrays[i].back())
                    continue;
                else {

                    answer = max(answer, max(abs(arrays[i][0]-cur_max), abs(arrays[i].back()-cur_min)));

                    min_max_same_arr = true;
                    if (cur_min > arrays[i][0]) {
                        min_max_same_arr = !min_max_same_arr;
                        cur_min = arrays[i][0];
                    }
                    if (cur_max < arrays[i].back()) {
                        min_max_same_arr = !min_max_same_arr;
                        cur_max = arrays[i].back();
                    }
                }
            }
        }

        return answer;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> nums;

    nums = {{-1,1},{-3,1,4},{-2,-1,0,2}};
    cout << sol.maxDistance(nums) << endl;

    nums = {{-8,-7,-7,-5,1,1,3,4},{-2},{-10,-10,-7,0,1,3},{2}};
    cout << sol.maxDistance(nums) << endl;
    return 0;
}