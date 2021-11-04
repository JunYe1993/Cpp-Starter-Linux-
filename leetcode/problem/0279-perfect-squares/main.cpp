#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>

using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:

    // DP
    int numSquares (int n) {

        vector<int> numSquareArray = {0};
        while ((int)numSquareArray.size() <= n) {
            int square = 1;
            int curNums = n;
            int m = numSquareArray.size();
            for (int i = 2; square <= m; ++i) {
                curNums = min (curNums, numSquareArray[m-square]+1);
                square = i * i;
            }
            numSquareArray.push_back(curNums);
        }

        return numSquareArray.back();
    }
    
    // BFS
    int numSquaresQ (int n) {

        vector<int> squares;
        for (int i = 1; i * i <= n; ++i)
            squares.push_back(i*i);

        
        vector<int> q = {n};
        for (int count = 0; count < n; ++count) {
            vector<int> temp;
            while (!q.empty()) {
                int rest = q.back();
                for (auto&s : squares) {
                    if (rest == s) return count+1;
                    else if (rest < s) break;
                    else if (rest > s) temp.push_back(rest-s);
                }
                q.pop_back();
            }
            q = temp;
        }

        return 0;
    }
};

int main () {

    Solution sol;
    
    cout << sol.numSquares (12) << endl;
    cout << sol.numSquares (13) << endl;

    return 0;
}