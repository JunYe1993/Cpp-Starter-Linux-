#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct Point
{
    int x;
    int y;
};

class Solution {
private:
    int size;
    vector<vector<bool>> map;
    void buildMap(vector<vector<int>>& grid, int num) {
        map.assign(size, vector<bool>(size, true));
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                if (grid[i][j] > num)
                    map[i][j] = false;
    }
    bool isMapIndexValid (int row, int col) {
        return (row >= 0 && row < size && col >= 0 && col < size);
    }
    bool isPathToEndExist () {
        int rowNum[] = {-1, 0, 0, 1};
        int colNum[] = { 0,-1, 1, 0};
        vector<vector<bool>> visited(size, vector<bool>(size, false));
        queue<struct Point> q;
        
        q.push({0,0});
        visited[0][0] = true;

        while (!q.empty())
        {
            struct Point curPoint = q.front();
            if (curPoint.x == size-1 && curPoint.y == size-1)
                return true;
            
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int row = curPoint.x + rowNum[i];
                int col = curPoint.y + colNum[i];
                
                if (isMapIndexValid(row, col) && map[row][col] && !visited[row][col])
                {
                    visited[row][col] = true;
                    q.push({row, col});
                }
            }
        }

        return false;
    }
public:

    int swimInWater(vector<vector<int>>& grid) {
        size = (int) grid.size();
        int min = (grid[0][0] > grid[size-1][size-1]) ? grid[0][0]:grid[size-1][size-1];
        int max = size*size - 1;
        int answer = max;
        int mid;
        
        while (min < max) {
            mid = (min + max) / 2;
            buildMap (grid, mid);
            if (isPathToEndExist()) {
                if (answer > mid)
                    answer = mid;
                if (max == mid) break;
                max = mid;
            } else {
                if (min == mid) break;
                min = mid;
            }
        }
        return answer;
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> nums;
    
    nums = {
        { 0, 1, 2, 3, 4},
        {24,23,22,21, 5},
        {12,13,14,15,16},
        {11,17,18,19,20},
        {10, 9, 8, 7, 6}
    };
    // nums = {{3,2}, {0,1}};
    // nums = {{0,3}, {1,2}};
    cout << sol.swimInWater(nums) << endl;
    return 0;
}