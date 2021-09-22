#include<iostream>
#include<vector>
#include<string> 

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
    }
};
int main () {
    Solution sol;
    int n;

    n = 3;
    for (auto&s:sol.fizzBuzz(n))
        cout << s << " ";
    cout << endl;

    n = 5;
    for (auto&s:sol.fizzBuzz(n))
        cout << s << " ";
    cout << endl;

    n = 15;
    for (auto&s:sol.fizzBuzz(n))
        cout << s << " ";
    cout << endl;

    return 0;
}