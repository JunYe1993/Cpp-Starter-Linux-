#include<iostream>
#include<math.h>

using namespace std;

class Solution {
public:
    uint32_t reverseBits (uint32_t n) {
        uint32_t ret = 0;
        for (int i = 0; i < 32; ++i) {
            if (n % 2 == 0) ret += (uint32_t)pow(2, i);
            n /= 2;
        }
        return ret;
    }
};

int main() {
    Solution sol;
    unsigned int num;

    num = 43261596;
    cout << sol.reverseBits(num) << endl;

    num = 4294967293;
    cout << sol.reverseBits(num) << endl;

    return 0;
}