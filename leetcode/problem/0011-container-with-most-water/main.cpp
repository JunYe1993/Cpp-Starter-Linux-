#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea (vector<int>& height) {
        int size = height.size();
        int left = 0, right = size-1;
        int curSize, maxSize = 0;
        
        --size;
        while (left < right) {
            if (height[left] < height[right]) curSize = height[left++]*size--;
            else curSize = height[right--]*size--;
            maxSize = max(maxSize, curSize);
        }

        return maxSize;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> height;

    height = {1,8,6,2,5,4,8,3,7};
    cout << sol.maxArea(height) << endl;
    height = {1,1};
    cout << sol.maxArea(height) << endl;
    height = {4,3,2,1,4};
    cout << sol.maxArea(height) << endl;
    height = {1,2,1};
    cout << sol.maxArea(height) << endl;

    return 0;
}