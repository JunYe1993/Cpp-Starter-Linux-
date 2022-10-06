#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) 
            return x;
        
        long num;
        int pivot, left = 2, right = x / 2;
        while (left <= right) {
            pivot = (left+right)/2;
            num = (long)pivot*pivot;
            if (num == x) return pivot;
            else {
                if (num > x) right = pivot-1;
                if (num < x) left  = pivot+1;
            }
        }
        return right;
    }
};

int main() {
    int ret;
    Solution sol;
    
    cin >> ret;
    cout << sol.mySqrt(ret) << endl;
    return 0;
}