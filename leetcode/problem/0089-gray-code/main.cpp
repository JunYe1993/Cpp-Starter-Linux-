#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> answer = {0, 1};
        for (int i = 1; i < n; ++i) {
            int size = answer.size();
            answer.resize(size*2);
            // for (auto&n : answer)
            //     cout << n << " ";
            // cout << endl;
            for (int j = size; j < size*2; ++j) {
                // cout << "j = " << j << endl;
                // cout << "value = " << pow(2, i) << endl;
                // cout << "index = " << size*2-j-1 << endl;
                // cout << "mirror = " << answer[size*2-j-1] << endl;
                answer[j] = pow(2, i) + answer[size*2-j-1];
            }
        }
        return answer;
    }
};

int main() {
    Solution sol;
    int n;

    n = 1;
    for (auto&n : sol.grayCode(n))
        cout << n << " ";
    cout << endl;

    n = 2;
    for (auto&n : sol.grayCode(n))
        cout << n << " ";
    cout << endl;

    n = 3;
    for (auto&n : sol.grayCode(n))
        cout << n << " ";
    cout << endl;

    return 0;
}