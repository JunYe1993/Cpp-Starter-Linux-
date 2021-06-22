#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int min = (int)s.size();
        map<char, int> myMap;
        for (int i = 0; i < min; ++i) {
            if (myMap.find(s[i]) == myMap.end())
                myMap[s[i]] = i;
            else 
                myMap[s[i]] = min;
        }

        for(auto const& [key, val] :myMap)
            if (min > val)
                min = val;

        if (min == (int)s.size()) return -1;    
        return min;
    }

    // 利用 26 個字母, 直接用 arr
    int firstUniqChar(string s) {
        vector<int> v(26,0);
		for(char c : s) v[c - 'a']++;
		for(int i = 0; i < s.length(); i++){
			if(v[s[i] - 'a'] == 1) return i;
		}
		return -1;
    }
};

int main() {
    Solution sol = Solution();
    string s;
    
    s = "aabb";
    cout << sol.firstUniqChar(s) << endl;

    s = "loveleetcode";
    cout << sol.firstUniqChar(s) << endl;

    return 0;
}