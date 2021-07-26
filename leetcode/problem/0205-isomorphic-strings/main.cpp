#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int size = s.size();
        vector<int> s_arr(128, -1);
        vector<int> t_arr(128, -1);

        for (int i = 0; i < size; ++i) {
            int sc = s[i];
            int tc = t[i];
            if (s_arr[sc] == -1) s_arr[sc] = i;
            if (t_arr[tc] == -1) t_arr[tc] = i;
            if (s_arr[sc] != t_arr[tc]) return false;
        }
        return true;
    }
    bool isIsomorphicQ(string s, string t) {
        map<char, int> s_dict;
        map<char, int> t_dict;
        int size = s.size();

        for (int i = 0; i < size; ++i) {
            if (s_dict.find(s[i]) == s_dict.end()) s_dict[s[i]] = i;
            if (t_dict.find(t[i]) == t_dict.end()) t_dict[t[i]] = i;
            if (s_dict[s[i]] != t_dict[t[i]]) return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    string s, t;

    s = "egg"; t = "add";
    cout << sol.isIsomorphic(s, t) << endl;

    s = "foo"; t = "bar";
    cout << sol.isIsomorphic(s, t) << endl;

    s = "paper"; t = "title";
    cout << sol.isIsomorphic(s, t) << endl;

    return 0;
}