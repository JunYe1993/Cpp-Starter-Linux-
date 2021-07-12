#include<iostream>
#include<string>
#include<map>

using namespace std;

class Solution {
    map<char, int> RomanChars = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
public:
    int romanToInt(string s) {
        int sum = 0, temp = 0;
        char pre;
        
        for (auto&c:s) {
            // cout << "Sum = " << sum << ", temp = " << temp << endl;
            if (c == 'I' || c == 'X' || c == 'C') {
                if (temp == 0) 
                    temp += RomanChars[c];
                else {
                    if (c != pre) {
                        if (RomanChars[c] > temp) sum -= temp;
                        else sum += temp;
                        temp = RomanChars[c];
                    } else 
                        temp += RomanChars[c];
                }
                pre = c;
            } else {
                if (temp != 0) {
                    if (RomanChars[c] > temp) sum -= temp;
                    else sum += temp;
                    temp = 0;
                }
                sum += RomanChars[c];
            }
        }
        return sum + temp;
    }
};

int main() {
    Solution sol = Solution();
    string str;
    
    str = "III";
    cout << sol.romanToInt(str) << endl;

    str = "IV";
    cout << sol.romanToInt(str) << endl;

    str = "IX";
    cout << sol.romanToInt(str) << endl;

    str = "LVIII";
    cout << sol.romanToInt(str) << endl;

    str = "MCMXCIV";
    cout << sol.romanToInt(str) << endl;
    
    str = "MDCCCLXXXIV";
    cout << sol.romanToInt(str) << endl;

    return 0;
}