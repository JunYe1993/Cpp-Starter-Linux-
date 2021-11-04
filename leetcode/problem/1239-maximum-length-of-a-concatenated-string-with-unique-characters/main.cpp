#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxLength (vector<string>& arr) {
        
        vector<bitset<26>> dicts = {bitset<26>()};
        int res = 0;
        
        for (auto& s : arr) {

            // init
            bitset<26> temp_dict;
            for (char c : s) temp_dict.set(c-'a');
            
            // skip when there has duplicate.
            if (temp_dict.count() < s.size()) continue;

            //
            for (int i = dicts.size()-1; i >= 0; --i) {
                bitset<26> cur_dict = dicts[i];
                if ((cur_dict&temp_dict).any()) continue;
                dicts.push_back(cur_dict|temp_dict);
                res = max(res, (int)dicts.back().count());
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<string> arr;

    arr = {"un","iq","ue"};
    cout << sol.maxLength(arr) << endl;
    arr = {"cha","r","act","ers"};
    cout << sol.maxLength(arr) << endl;
    arr = {"abcdefghijklmnopqrstuvwxyz"};
    cout << sol.maxLength(arr) << endl;
    arr = {"yy","bkhwmpbiisbldzknpm"};
    cout << sol.maxLength(arr) << endl;
    arr = {"a", "abc", "d", "de", "def"};
    cout << sol.maxLength(arr) << endl;

    return 0;
}