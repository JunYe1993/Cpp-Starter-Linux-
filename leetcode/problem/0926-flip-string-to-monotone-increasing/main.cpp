#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
    struct path {
        char preChar;
        int cost;
    };
public:

    // 發現從 0 轉出來的 1 path, 若比原本的 1 path 短, 那不管後面是啥都比原本的 1 path 短
    int minFlipsMonoIncr(string s) {
        array<int, 2> twoPath = {0, 0};
        for (auto&c:s) {
            if (c == '0') ++twoPath[1];
            else {
                twoPath[1] = min(twoPath[0], twoPath[1]);
                ++twoPath[0];
            }
        }
        return min(twoPath[0], twoPath[1]);
    }

    // 原想法
    int minFlipsMonoIncrQ(string s) {
        
        int size = s.size();
        vector<struct path> paths;
        paths.push_back({s[0], 0});
        if (s[0] == '1') paths.push_back({'0', 1});
        
        for (int i = 1; i < size; ++i) {
            int paths_size = paths.size();
            for (int j = 0; j < paths_size; ++j) {
                if (s[i] == '0') {
                    if (paths[j].preChar == '0') ;
                    if (paths[j].preChar == '1') ++paths[j].cost;
                }
                if (s[i] == '1') {
                    if (paths[j].preChar == '0') {
                        if (i > 0 && s[i-1] == '0')
                            paths.push_back({'1', paths[j].cost});
                        ++paths[j].cost;
                    }
                    if (paths[j].preChar == '1') ;
                }
            }

            // cout << "Current char = " << s[i] << endl;
            // for (auto&path:paths)
            //     cout << "Char = " << path.preChar << ", cost = " << path.cost << endl;
            // cout << endl;
        }

        int minCost = 100000;
        for (auto&path:paths)
            minCost = min(minCost, path.cost);

        return minCost;
    }
};

int main() {
    Solution sol;
    string str;

    str = "00110";
    str = "010110";
    str = "00011000";
    cout << sol.minFlipsMonoIncr(str) << endl;
    
    return 0;
}