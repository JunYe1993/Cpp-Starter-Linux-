#include<iostream>
#include<vector>
#include<string> 

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ret;
        int num;
        for (int i = 0; i < n; ++i) {
            num = i + 1;
            bool div3 = (num % 3) == 0;
            bool div5 = (num % 5) == 0;
            if (div3 && div5) ret.push_back("FizzBuzz");
            else if (div3) ret.push_back("Fizz");
            else if (div5) ret.push_back("Buzz");
            else ret.push_back(to_string(num));
        }
        return ret;
    }
};

int main () {
    Solution sol;
    int n;

    n = 3;
    for (auto&s:sol.fizzBuzz(n))
        cout << s << " ";
    cout << endl;

    n = 5;
    for (auto&s:sol.fizzBuzz(n))
        cout << s << " ";
    cout << endl;

    n = 15;
    for (auto&s:sol.fizzBuzz(n))
        cout << s << " ";
    cout << endl;

    return 0;
}