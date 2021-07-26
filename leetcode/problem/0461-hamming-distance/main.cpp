#include<iostream>
#include<vector>
#include<string> 

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        while (x | y) {
            if ( x%2 != y%2 ) ++count;
            x /= 2;
            y /= 2;
        }
        return count;
    }
};

int main () {
    Solution sol;
    int x, y;

    x = 1, y = 4;
    cout << sol.hammingDistance(x, y) << endl;

    x = 3, y = 1;
    cout << sol.hammingDistance(x, y) << endl;

    return 0;
}