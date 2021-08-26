#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
    struct backets {
        int backet1;
        int backet2;
        backets() : backet1(-1), backet2(-1) {}
    };
public:
    int totalFruit(vector<int>& fruits) {
        
        int size = fruits.size();
        int maxWindow = 0;
        int curWindow = 0;
        int preContinueIndex = 0;
        
        struct backets b;
        for (int i = 0; i < size; ++i) {
            // printf("Before cur = %d, max = %d.\n", curWindow, maxWindow);
            // printf("Set[0] = %d, Set[1] = %d\n", set[0], set[1]);
            if (b.backet1 == -1 || b.backet1 == fruits[i]) {
                b.backet1 = fruits[i];
                maxWindow = max(maxWindow, ++curWindow);
            } else if (b.backet2 == -1) {
                b.backet2 = fruits[i];
                maxWindow = max(maxWindow, ++curWindow);
            } else {
                if (fruits[i] != b.backet1 && fruits[i] != b.backet2) {
                    b.backet1 = fruits[i];
                    b.backet2 = fruits[preContinueIndex];
                    curWindow = i - preContinueIndex + 1;
                } else {
                    maxWindow = max(maxWindow, ++curWindow);
                }
            }
            
            if (i != 0) 
                if (fruits[i] != fruits[i-1])
                    preContinueIndex = i;
        }

        return maxWindow;
    }
};

int main() {
    Solution sol;
    vector<int> fruits;

    fruits = {1,2,1};
    cout << sol.totalFruit(fruits) << endl;
    fruits = {0,1,2,2};
    cout << sol.totalFruit(fruits) << endl;
    fruits = {1,2,3,2,2};
    cout << sol.totalFruit(fruits) << endl;
    fruits = {3,3,3,1,2,1,1,2,3,3,4};
    cout << sol.totalFruit(fruits) << endl;
    fruits = {3,3,3,1,4};
    cout << sol.totalFruit(fruits) << endl;
    
    return 0;
}