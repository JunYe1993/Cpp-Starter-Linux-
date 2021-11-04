#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {

    struct tracker {
        int start;
        int end;
        int index;
    };

public:
    string findReplaceString (string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        
        int size = indices.size();
        vector<struct tracker> checkList;
        for (int i = 0; i < size; ++i) {
            int srcLen = sources[i].size();
            if (s.substr(indices[i], srcLen) == sources[i])
                checkList.push_back({indices[i], indices[i]+srcLen-1, i});
        }

        if (checkList.empty()) return s; 
        sort(checkList.begin(), checkList.end(), 
            [](struct tracker& a, struct tracker& b){
                return a.start < b.start;
            }
        );
        for (int i = checkList.size()-2; i >= 0; --i) {
            if (checkList[i].end >= checkList[i+1].start) {
                checkList.erase(checkList.begin() + i);
                checkList.erase(checkList.begin() + i);
            }
        }

        for (int i = checkList.size()-1; i >= 0; --i) {
            // printf("s : %2d, e : %2d, i : %2d\n", checkList[i].start, checkList[i].end, checkList[i].index);
            s = s.substr(0, checkList[i].start) + 
                targets[checkList[i].index] +
                s.substr(checkList[i].end+1, (int)s.size()-checkList[i].end-1);
            // cout << s << endl;
        }
        return s;
    }
};

int main() {
    
    Solution sol;
    string str;
    vector<int> indices;
    vector<string> sources;
    vector<string> targets;

    // str = "abcd";
    // indices = {0, 2};
    // sources = {"a", "cd"};
    // targets = {"eee", "ffff"};
    // cout << sol.findReplaceString(str, indices, sources, targets) << endl;
    // str = "abcd";
    // indices = {0, 2};
    // sources = {"ab", "ec"};
    // targets = {"eee", "ffff"};
    // cout << sol.findReplaceString(str, indices, sources, targets) << endl;
    str = "vmokgggqzp";
    indices = {3, 5, 1};
    sources = {"kg","ggq","mo"};
    targets = {"s","so","bfr"};
    cout << sol.findReplaceString(str, indices, sources, targets) << endl;

    return 0;
}