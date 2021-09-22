#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    string multiply (string num1, string num2) {
        int num1size = num1.size()-1;
        int num2size = num2.size()-1;
        vector<int> ans(num1.size()+num2.size(), 0);
        for (int i = num1size, idigit = 0; i >= 0; --i, ++idigit) {
            for (int j = num2size, jdigit = 0; j >= 0; --j, ++jdigit) {
                int x = num1[i] - '0';
                int y = num2[j] - '0';
                ans[idigit+jdigit] += x * y;
            }
        }

        int carry = 0;
        string answer;
        for (auto & n: ans) {
            n += carry;
            answer.push_back('0'+(n%10));
            carry = n / 10;
        }
        while (answer.size() > 1 && answer.back() == '0') answer.pop_back();
        reverse(answer.begin(), answer.end());
        return answer;
    }
};

int main() {
    Solution sol = Solution();
    string num1, num2;
    
    num1 = "2";
    num2 = "3";
    cout << sol.multiply (num1, num2) << endl;
    num1 = "123";
    num2 = "456";
    cout << sol.multiply (num1, num2) << endl;
    num1 = "0";
    num2 = "1123";
    cout << sol.multiply (num1, num2) << endl;

    return 0;
}