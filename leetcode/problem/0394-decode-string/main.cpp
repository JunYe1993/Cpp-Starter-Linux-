#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {

    string decodeString (string& s, int& index, int size) {

        string res = "";
        for (;index < size; ++index) {

            if (isdigit(s[index])) {
                int count = 0;
                while (s[index] != '[')
                    count = count*10 + (s[index++] - '0');
                string tmp = decodeString(s, ++index, size);
                // printf("count = %2d, tmp = %s\n", count, tmp.c_str());
                for (int i = 0; i < count; ++i) res += tmp;
            }
            else if (s[index] == ']')
                return res;
            else 
                res += s[index];
        }
        return res;
    }

public:
    string decodeString (string s) {
        
        int size = s.size();
        int index = 0;
        return decodeString(s, index, size);

    }
};

int main() {
    Solution sol = Solution();
    string s;
    
    s = "3[a]2[bc]";
    cout << sol.decodeString(s) << endl;
    s = "3[a2[c]]";
    cout << sol.decodeString(s) << endl;
    s = "2[abc]3[cd]ef";
    cout << sol.decodeString(s) << endl;
    s = "abc3[cd]xyz";
    cout << sol.decodeString(s) << endl;

    return 0;
}