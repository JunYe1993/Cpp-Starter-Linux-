#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    int findIntegersQ (int n) {
        vector<int> v = {0, 1};
        vector<int> temp;
        int x = 1;
        while (x < n) {
            temp = v;
            for (auto & num : temp) {
                if (num - x < 0)
                    v.push_back(num+x*2);
                else
                    break;
            }
            x *= 2;
        }
        // for (auto & num : v)
        //     cout << num << " ";
        // cout << endl;
        for (auto it = v.end()-1; *it > n;) {
            --it;
            v.pop_back();
        }

        return v.size();
    }
    int findIntegers(int num) {
        vector<int> bits;
        for(;num > 0; num >>= 1)
            bits.push_back(num & 1);

        // for(auto&b:bits)
        //     cout << b << " ";
        // cout << endl;

        int n = bits.size();
        vector<int> total = {1, 2};
        vector<int> endw1 = {0, 1};
        for (int i = 2; i <= n; ++i) {
            int preTotal = total.back();
            int preEndw1 = endw1.back();
            total.push_back(preTotal+preEndw1);
            endw1.push_back(preTotal);
        }

        int answer = total.back();
        for (int i = n - 2; i >= 0; i--)
            if (bits[i] == 0 && bits[i + 1] == 0)
                answer -= endw1[i+1];
            else if (bits[i] == 1 && bits[i + 1] == 1)
                break;
        return answer;
    }
};

int main() {
    Solution sol;
    int n;

    n = 5;
    cout << sol.findIntegers(n) << endl;

    n = 1;
    cout << sol.findIntegers(n) << endl;

    n = 2;
    cout << sol.findIntegers(n) << endl;

    n = 918332516;
    cout << sol.findIntegers(n) << endl;
    // 2178309

    return 0;
}