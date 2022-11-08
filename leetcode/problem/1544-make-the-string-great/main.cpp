#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
    bool is_bad (char a, char b) {
        return (abs(a-b) == 32);
    }
public:
    string makeGood (string s) {
        string stack = "";
        for (auto&c:s) {
            if (stack == "")
                stack += c;
            else {
                if (is_bad(stack.back(), c))
                    stack.pop_back();
                else {
                    stack += c;
                }
            }
        }
        return stack;
    }
};

int main() {

    Solution sol;

    cout << sol.makeGood("leEeetcode") << endl;
    cout << sol.makeGood("abBAcC") << endl;
    cout << sol.makeGood("s") << endl;

    return 0;
}