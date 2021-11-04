#include <iostream>
#include <vector>
#include <string> 
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    string frequencySort (string s) {
        
        unordered_map<char, int> map;
        for (auto&c:s) ++map[c];
        vector<pair<char, int>> vec(map.begin(), map.end());
        
        sort (vec.begin(), vec.end(), [](pair<char, int>& a, pair<char, int>& b){
            return (a.second == b.second) ? (a.first < b.first) : (a.second > b.second);
        });

        string res;
        for (auto&v:vec) res += string(v.second, v.first);
        return res;
    }
};

int main () {
    Solution sol;
    string str;

    str = "tree";
    cout << sol.frequencySort(str) << endl;
    str = "cccaaa";
    cout << sol.frequencySort(str) << endl;
    str = "Aabb";
    cout << sol.frequencySort(str) << endl;

    return 0;
}