#include <iostream>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        
        string toBeSaid = countAndSay(n-1);
        string ret = "";
        char cur = '*';
        int count = 0;

        for (auto&c:toBeSaid) {
            if (cur == '*') {
                cur = c;
                count = 1;
            } else if (cur == c) {
                ++count;
            } else {
                ret += to_string(count);
                ret += cur;
                cur = c;
                count = 1;
            }
        }
        ret += to_string(count);
        ret += cur;
        return ret;
    }
};

int main() {
    Solution sol = Solution();
    int n;
    
    n = 1;
    cout << sol.countAndSay(n) << endl;
    n = 2;
    cout << sol.countAndSay(n) << endl;
    n = 4;
    cout << sol.countAndSay(n) << endl;

    return 0;
}