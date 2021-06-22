#include <iostream>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        enum {
            LEADING_SPACE,
            POSI_NEGATIVE,
            DIGIT
        };
        int signBit = 1;
        int state = 0;
        int answer = 0;

        for (auto&c:s) {
            
            if (state == LEADING_SPACE) {
                if (c == ' ')
                    continue;
                else
                    ++state;
            }
            
            if (state == POSI_NEGATIVE) {
                ++state;
                if (c == '+')
                    continue;
                else if (c == '-') {
                    signBit = -1;
                    continue;
                }
            }

            if (state == DIGIT) {
                if (isdigit(c)) {
                    int carry = c-'0';
                    if (answer > INT_MAX/10)
                        return INT_MAX;
                    else if (answer < INT_MIN/10)
                        return INT_MIN;
                    else {
                        answer *= 10;
                        if (answer > INT_MAX - carry)
                            return INT_MAX;
                        else if (answer < INT_MIN + carry)                    
                            return INT_MIN;

                        answer += carry*signBit;
                    }  
                } else
                    break;
            }
        }

        return answer;
    }
};

int main() {
    Solution sol = Solution();
    string s, t;
    
    s = "42";
    cout << sol.myAtoi(s) << endl;

    s = "       -42";
    cout << sol.myAtoi(s) << endl;

    s = "4193 with words";
    cout << sol.myAtoi(s) << endl;

    s = "words and 987";
    cout << sol.myAtoi(s) << endl;

    s = "-91283472332";
    cout << sol.myAtoi(s) << endl;

    s = "+-91283472332";
    cout << sol.myAtoi(s) << endl;
    

    s = "-2147483648";
    cout << sol.myAtoi(s) << endl;

    return 0;
}