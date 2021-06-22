#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int start=0, end = (int)s.size()-1; start < end; start++, end--)
            swap(s[start], s[end]);
    }
};
        

int main() {
    Solution sol = Solution();
    vector<char> chars;

    chars = {'h','e','l','l','o'};
    sol.reverseString(chars);
    for(auto&c:chars)
        cout << c << ' ';
    cout << endl;

    return 0;
}