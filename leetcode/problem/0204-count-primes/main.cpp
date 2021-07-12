#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) return 0;
        vector<bool> prime(n, true);
        prime[0] = false; 
        prime[1] = false;
        for (int i = 0; i*i < n; ++i) {
            if (prime[i]) {
                for (int j = i*i; j < n; j += i) {
                    prime[j] = false;
                }    
            }    
        }
        return count(prime.begin(), prime.end(), true);
    }
};

int main() {
    Solution sol;
    int num;

    num = 10;
    cout << sol.countPrimes(num) << endl;

    num = 0;
    cout << sol.countPrimes(num) << endl;

    num = 12;
    cout << sol.countPrimes(num) << endl;

    return 0;
}