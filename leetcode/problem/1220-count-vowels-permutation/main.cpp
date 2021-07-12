#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
// Each vowel 'a' may only be followed by an 'e'.
// Each vowel 'e' may only be followed by an 'a' or an 'i'.
// Each vowel 'i' may not be followed by another 'i'.
// Each vowel 'o' may only be followed by an 'i' or a 'u'.
// Each vowel 'u' may only be followed by an 'a'.

class Solution {
    vector<map<char, int>> dp;
    int mod = 1000000007;
    int countFollowPermutation (char c, int length) {
        if (length == 0) return 1;
        if (dp[length].find(c) != dp[length].end()) return dp[length][c];
        int count = 0;
        switch (c) {
            case 'a':
                count = (count % mod) + countFollowPermutation('e', length-1);
                break;
            case 'e':
                count = (count % mod) + countFollowPermutation('a', length-1);
                count = (count % mod) + countFollowPermutation('i', length-1);
                break;
            case 'i':
                count = (count % mod) + countFollowPermutation('a', length-1);
                count = (count % mod) + countFollowPermutation('e', length-1);
                count = (count % mod) + countFollowPermutation('o', length-1);
                count = (count % mod) + countFollowPermutation('u', length-1);
                break;
            case 'o':
                count = (count % mod) + countFollowPermutation('i', length-1);
                count = (count % mod) + countFollowPermutation('u', length-1);
                break;
            case 'u':
                count = (count % mod) + countFollowPermutation('a', length-1);
                break;
        }
        dp[length][c] = count % mod;
        return count % mod;
    }
public:
    int countVowelPermutation(int n) {
        int count = 0;
        dp.resize(n);
        count = (count % mod) + countFollowPermutation('a', n-1);
        count = (count % mod) + countFollowPermutation('e', n-1);
        count = (count % mod) + countFollowPermutation('i', n-1);
        count = (count % mod) + countFollowPermutation('o', n-1);
        count = (count % mod) + countFollowPermutation('u', n-1);
        return count % mod;
    }
};

int main() {
    Solution sol;
    int num;

    num = 1;
    cout << sol.countVowelPermutation(num) << endl;

    num = 2;
    cout << sol.countVowelPermutation(num) << endl;

    num = 5;
    cout << sol.countVowelPermutation(num) << endl;

    num = 144;
    cout << sol.countVowelPermutation(num) << endl;

    return 0;
}