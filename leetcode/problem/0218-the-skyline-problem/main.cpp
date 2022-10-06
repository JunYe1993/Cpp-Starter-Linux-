#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {

        // Iterate over all buildings, for each building i,
        // add (position, i) to edges.
        vector<vector<int>> edges;
        for (int i = 0; i < (int)buildings.size(); ++i){
            edges.push_back({buildings[i][0], i});
            edges.push_back({buildings[i][1], i});
        }

        // Sort edges by non-decreasing order.
        sort(edges.begin(), edges.end());

        // Initailize an empty Priority Queue 'live' to store all the newly added buildings,
        // an empty list 'answer' to store the skyline key points.
        priority_queue<pair<int, int>> live;
        vector<vector<int>> answer;
        int idx = 0;

        // Iterate over all the sorted edges.
        while (idx < (int)edges.size()){

            // Since we might have multiple edges at same x,
            // Let the 'currX' be the current position.
            int currX = edges[idx][0];

            // While we are handling the edges at 'currX':
            while (idx < (int)edges.size() && edges[idx][0] == currX){
                // The index 'b' of this building in 'buildings'
                int b = edges[idx][1];

                // If this is a left edge of building 'b', we
                // add (height, right) of building 'b' to 'live'.
                if (buildings[b][0] == currX){
                    int right = buildings[b][1];
                    int height = buildings[b][2];
                    live.push({height, right});
                }
                idx += 1;
            }

            // If the tallest live building has been passed,
            // we remove it from 'live'.
            while (!live.empty() && live.top().second <= currX)
                live.pop();

            // Get the maximum height from 'live'.
            int currHeight = live.empty() ? 0 : live.top().first;

            // If the height changes at 'currX', we add this
            // skyline key point [currX, max_height] to 'answer'.
            if (answer.empty() || answer[answer.size() - 1][1] != currHeight)
                answer.push_back({currX, currHeight});
        }

        // Return 'answer' as the skyline.
        return answer;
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> nums;

    // nums = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    // for (auto&v:sol.getSkyline(nums)) {
    //     for (auto&n:v)
    //         cout << n << " ";
    //     cout << endl;
    // }
//
    // nums = {{0,2,3},{2,5,3}};
    // for (auto&v:sol.getSkyline(nums)) {
    //     for (auto&n:v)
    //         cout << n << " ";
    //     cout << endl;
    // }

    nums = {
        {1,38,219},
        {2,19,228},
        {2,64,106},
        {3,80,65},
        {3,84,8},
        {4,12,8},
        {4,25,14},
        {4,46,225},
        {4,67,187},
        {5,36,118},
        {5,48,211},
        {5,55,97},
        {6,42,92},
        {6,56,188},
        {7,37,42},
        {7,49,78},
        {7,84,163},
        {8,44,212},
        {9,42,125},
        {9,85,200},
        {9,100,74},
        {10,13,58},
        {11,30,179},
        {12,32,215},
        {12,33,161},
        {12,61,198},
        {13,38,48},
        {13,65,222},
        {14,22,1},
        {15,70,222},
        {16,19,196},
        {16,24,142},
        {16,25,176},
        {16,57,114},
        {18,45,1},
        {19,79,149},
        {20,33,53},
        {21,29,41},
        {23,77,43},
        {24,41,75},
        {24,94,20},
        {27,63,2},
        {31,69,58},
        {31,88,123},
        {31,88,146},
        {33,61,27},
        {35,62,190},
        {35,81,116},
        {37,97,81},
        {38,78,99},
        {39,51,125},
        {39,98,144},
        {40,95,4},
        {45,89,229},
        {47,49,10},
        {47,99,152},
        {48,67,69},
        {48,72,1},
        {49,73,204},
        {49,77,117},
        {50,61,174},
        {50,76,147},
        {52,64,4},
        {52,89,84},
        {54,70,201},
        {57,76,47},
        {58,61,215},
        {58,98,57},
        {61,95,190},
        {66,71,34},
        {66,99,53},
        {67,74,9},
        {68,97,175},
        {70,88,131},
        {74,77,155},
        {74,99,145},
        {76,88,26},
        {82,87,40},
        {83,84,132},
        {88,99,99}
    };
    for (auto&v:sol.getSkyline(nums)) {
        for (auto&n:v)
            cout << n << " ";
        cout << endl;
    }
    return 0;
}