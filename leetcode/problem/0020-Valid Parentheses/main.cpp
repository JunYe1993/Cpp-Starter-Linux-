#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        map<char, int> dict = {
            {'(', 1},
            {'[', 2},
            {'{', 3},
            {')', -1},
            {']', -2},
            {'}', -3}
        };

        for (auto&c:s) {
            if (dict[c] > 0) stack.push_back(dict[c]);
            else {
                if (stack.empty() || stack.back()+dict[c] != 0) return false;
                else stack.pop_back();
            }
        }
        return stack.empty();
    }
};

int main() {
    Solution sol;
    string str;

    str = "";
    cout << sol.isValid(str) << endl;

    str = "()";
    cout << sol.isValid(str) << endl;

    str = "()[]{}";
    cout << sol.isValid(str) << endl;

    str = "(]";
    cout << sol.isValid(str) << endl;

    str = "([)]";
    cout << sol.isValid(str) << endl;

    str = "{[]}";
    cout << sol.isValid(str) << endl;

    return 0;
}