#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <stdio.h>

using namespace std;

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        
        int count = 0;
        int mask1 = 0x80; 
        int mask2 = 0x40;
        int mask3 = 0x20;
        int mask4 = 0x10;
        int mask5 = 0x08;
        
        for (int&num:data) {
            printf("Num : %d\n", num);
            if (count == 0) {
                printf("ishead\n");
                if ((num & mask1) != 0) {
                    if ((num & mask2) != 0) {
                        ++count;
                        if ((num & mask3) == 0)
                            continue;
                        else 
                            ++count;
                        if ((num & mask4) == 0)
                            continue;
                        else 
                            ++count;
                        if ((num & mask5) == 0)
                            continue;
                        else
                            return false;
                    } else
                        return false;
                } 
            } else if (((num & mask1) != 0) && ((num & mask2) == 0)) {
                printf("istail count = %d\n", count);
                --count;
            } else {
                printf("istail but wrong\n");
                return false;
            }
                
        }

        return count == 0;
    }
};

int main() {
    
    Solution sol;
    vector<int> test1 = {197,130,1};
    cout << sol.validUtf8(test1) << endl;
    vector<int> test2 = {235,140,4};
    cout << sol.validUtf8(test2) << endl;

    return 0;
}