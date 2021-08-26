#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_set>

using namespace std;

class Solution {
public:

    bool judgeSquareSum (int c) {
        vector<int> squares;
        long long square, num = 0;
        do {
            square = num * num;
            if (square == c) return true;
            if (square < c) squares.push_back(square);
            ++num;
        } while (square <= c);

        for (int i = 0, j = (int)squares.size()-1; i <= j; ) {
            int sum = c-squares[i]-squares[j];
            // cout << "Sum: " << sum << endl;
            if (sum == 0) return true;
            else if (sum < 0) --j;
            else if (sum > 0) ++i;
        }
        return false;
    }

    bool judgeSquareSumQ (int c) {
        vector<int> squares;
        int i = 0;
        long long square;
        bool is_c_even = !(c%2);
        int halfc = c/2;
        do {
            square = (long long)i * (long long)i;
            if (square == c) return true;
            if (is_c_even && square == halfc) return true;
            squares.push_back(square);
            ++i;
        } while (square < c);
        squares.pop_back();

        unordered_set<long long> set;
        for (auto&sq:squares) {
            if (set.find(sq) != set.end())
                return true;
            else 
                set.insert(c-sq);
        }

        return false;
    }
};

int main() {
    Solution sol;
    int n;

    n = 7;
    printf("Answer: %5s\n", (sol.judgeSquareSum(n))?"true":"false");
    n = 3;
    printf("Answer: %5s\n", (sol.judgeSquareSum(n))?"true":"false");
    n = 4;
    printf("Answer: %5s\n", (sol.judgeSquareSum(n))?"true":"false");
    n = 2;
    printf("Answer: %5s\n", (sol.judgeSquareSum(n))?"true":"false");
    n = 1;
    printf("Answer: %5s\n", (sol.judgeSquareSum(n))?"true":"false");

    return 0;
}