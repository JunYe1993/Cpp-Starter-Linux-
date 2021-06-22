#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (answer == INT_MIN) return 0;
        int signBit = 1;
        int answer = 0;
        if (x < 0) {
            signBit = -1;
            x *= signBit;
        }
        do {
            if (answer > INT_MAX/10) return 0;
            answer = (answer*10) + (x%10);
            x /= 10;
        } while (x > 0);

        
        return answer*signBit;        
    }
};
        

int main() {
    Solution sol = Solution();
    int num = 1534236469;
    cout << sol.reverse(num) << endl;

    return 0;
}