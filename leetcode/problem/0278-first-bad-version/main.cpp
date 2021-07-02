#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
    bool isBadVersion(int version) {
        return (version > 0);
    }
public:
    int firstBadVersion(int n) {
        int max = n, min = 1;
        while (min != max-1 && min != max) {
            int mid = ((long int)max+(long int)min) / 2;
            if (isBadVersion(mid)) max = mid;
            else min = mid;
        }
        return isBadVersion(min) ? min:max;
    }
};
int main() {
    Solution sol;
    cout << sol.firstBadVersion(21232) << endl;
    return 0;
}