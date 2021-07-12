#include<iostream>
#include<vector>
#include<string> 

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 0) return false;
        if (n == 1) return true;
        if (n % 3 != 0) return false;
        return isPowerOfThree(n/3);
    }
};

int main () {
    Solution sol;
    int n;

    n = 3;
    cout << sol.isPowerOfThree(n) << endl;
    n = 6;
    cout << sol.isPowerOfThree(n) << endl;
    n = -98;
    cout << sol.isPowerOfThree(n) << endl;

    return 0;
}