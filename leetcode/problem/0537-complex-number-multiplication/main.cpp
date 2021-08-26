#include <iostream>
#include <vector>
#include <string> 
#include <cctype>

using namespace std;

class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int x1, y1, x2, y2;
        
        auto spliter = num1.find('+');
        x1 = stoi(num1.substr(0, spliter));
        y1 = stoi(num1.substr(spliter+1, num1.size()-spliter-1));
        
        spliter = num2.find('+');
        x2 = stoi(num2.substr(0, spliter));
        y2 = stoi(num2.substr(spliter+1, num2.size()-spliter-1));

        int leftpart  = x1*x2 + y1*y2*(-1);
        int rightpart = x1*y2 + y1*x2;
        
        return to_string(leftpart) + '+' + to_string(rightpart) + 'i';
    }
};

int main () {
    Solution sol;
    string num1, num2;
    
    num1 = "1+1i";
    num2 = "1+1i";
    cout << sol.complexNumberMultiply(num1, num2) << endl;
    num1 = "1+-1i";
    num2 = "1+-1i";
    cout << sol.complexNumberMultiply(num1, num2) << endl;

    return 0;
}