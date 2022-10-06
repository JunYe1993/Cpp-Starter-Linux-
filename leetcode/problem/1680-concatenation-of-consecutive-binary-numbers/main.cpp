#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int concatenatedBinary(int n) {

        long long ret = 0;
        int topbit = 1, curbit = 1;

        for (int i = 1; i <= n; ++i) {
            ret = i + (ret << topbit);
            ret %= 1000000007;
            if (--curbit == 0) {
                curbit = 1 << topbit;
                ++topbit;
            }
        }

        return (int)ret;
    }
};

int main() {
    Solution sol;

    cout << sol.concatenatedBinary(1) << endl;
    cout << sol.concatenatedBinary(2) << endl;
    cout << sol.concatenatedBinary(3) << endl;
    cout << sol.concatenatedBinary(12) << endl;

    return 0;
}