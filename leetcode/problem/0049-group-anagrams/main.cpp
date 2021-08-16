#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groupStrs;
        unordered_map<string, int> map;
        int curIndex = 0;
        for (auto&s:strs) {
            string tempStr = s;
            sort(tempStr.begin(), tempStr.end());
            if (map.find(tempStr) == map.end()){
                map[tempStr] = curIndex++;
                groupStrs.push_back(vector<string>({s}));
            } else 
                groupStrs[map[tempStr]].push_back(s);
        }
        return groupStrs;
    }
};

int main() {
    Solution sol = Solution();
    vector<string> strs;

    strs = {"eat","tea","tan","ate","nat","bat"};
    for (auto&v:sol.groupAnagrams(strs)) {
        for (auto&s:v)
            cout << s << endl;
        cout << endl;
    }

    return 0;
}