#include<iostream>
#include<string>
#include<vector>
#include<math.h>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<char> RomanList = {'I','V','X','L','C','D','M'};
        string ret;
        int digit, curIndex = RomanList.size()-1;


        digit = num / 1000;
        ret += string(digit, RomanList[curIndex]);

        for (int digitIndex = 3; digitIndex > 0; --digitIndex) {
            curIndex = curIndex - 2;
            digit = (num / pow(10, digitIndex-1));
            digit %= 10;
            if (0 <= digit && digit <= 3) 
                ret += string(digit, RomanList[curIndex]);
            else if (digit == 4) {
                ret += RomanList[curIndex];
                ret += RomanList[curIndex+1];
            } else if (5 <= digit && digit <= 8) {
                ret += RomanList[curIndex+1];
                ret += string(digit-5, RomanList[curIndex]);
            } else {
                ret += RomanList[curIndex];
                ret += RomanList[curIndex+2];
            }
        }   

        return ret;
    }
};

int main() {
    Solution sol = Solution();
    int nums;
    
    // Test1
    cout << "Test1" << endl;
    nums = 3;
    cout << sol.intToRoman(nums) << endl;

    // Test1
    cout << "Test2" << endl;
    nums = 4;
    cout << sol.intToRoman(nums) << endl;

    // Test1
    cout << "Test3" << endl;
    nums = 9;
    cout << sol.intToRoman(nums) << endl;

    // Test1
    cout << "Test4" << endl;
    nums = 58;
    cout << sol.intToRoman(nums) << endl;

    // Test1
    cout << "Test5" << endl;
    nums = 1994;
    cout << sol.intToRoman(nums) << endl;

    return 0;
}