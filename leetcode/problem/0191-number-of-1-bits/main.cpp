#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            // 正常解
            // if (n % 2) ++count;
            // n /= 2;

            // 數學解
            n &= n - 1;
            ++count;
        }
        return count;
    }
};

int main() {
    Solution sol;
    int num;

    num = 11;
    cout << sol.hammingWeight(num) << endl;

    num = 128;
    cout << sol.hammingWeight(num) << endl;

    return 0;
}