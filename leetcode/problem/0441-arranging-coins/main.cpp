#include<iostream>
#include<vector>
#include<string> 

using namespace std;

class Solution {
public:
    int arrangeCoins (int n) {
        int res = -1, stair = 1;
        while (n >= 0) {
            n -= stair++;
            ++res;
        }
        return res;
    }
};

int main () {
    Solution sol;
    int n;

    n = 1;
    cout << sol.arrangeCoins(n) << endl;
    n = 8;
    cout << sol.arrangeCoins(n) << endl;
    
    return 0;
}