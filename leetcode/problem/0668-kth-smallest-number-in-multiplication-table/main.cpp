#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findKthNumber (int m, int n, int k) {

        int hi = m * n;
        int lo = 1;
        while (lo < hi) {
            int mid = (hi + lo) / 2;
            int count = 0;

            // check how many numbers are smaller than mid
            for (int i = 1; i <= m; ++i) {
                int pivot = mid / i;
                count += (n < pivot) ? n : pivot;
            }
            if (count >= k) hi = mid;
            else lo = mid + 1;
        }

        return lo;
    }
};

int main() {
    Solution sol;
    int m, n, k;

    m = 3;
    n = 3;
    k = 5;
    cout << sol.findKthNumber(m, n, k) << endl;
    m = 2;
    n = 3;
    k = 6;
    cout << sol.findKthNumber(m, n, k) << endl;

    return 0;
}