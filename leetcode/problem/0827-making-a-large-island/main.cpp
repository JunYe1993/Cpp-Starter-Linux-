#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
    int size;
    unordered_map<int, int> landsSize;
    vector<int> rowDir = {0, 1, 0,-1};
    vector<int> colDir = {1, 0,-1, 0};
    bool isValidIndex (int rowIndex, int colIndex) {
        return (0 <= rowIndex && rowIndex < size && 0 <= colIndex && colIndex < size);
    }
    void paint (vector<vector<int>>& grid, int rowIndex, int colIndex, int color) {
        if (!isValidIndex(rowIndex, colIndex)) return;
        if (grid[rowIndex][colIndex] != 1) return;  
        grid[rowIndex][colIndex] = color;
        landsSize[color] += 1;
        for (int i = 0; i < 4; ++i)
            paint (grid, rowIndex + rowDir[i], colIndex + colDir[i], color);
    }
    int paintGrid (vector<vector<int>>& grid) {
        int color = 2, maxSize = 0;
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                if (grid[i][j] == 1) {
                    paint (grid, i, j, color++);
                    maxSize = max(maxSize, landsSize[color-1]);
                }
        return maxSize; 
    }

public:
    
    int largestIsland (vector<vector<int>>& grid) {
        size = grid.size();
        if (size == 1) return 1;

        int maxSize = paintGrid (grid);

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (grid[i][j] == 0) {
                    unordered_set<int> neibor;
                    for (int index = 0; index < 4; ++index) {
                        int row = i+rowDir[index];
                        int col = j+colDir[index];
                        if (isValidIndex(row, col) &&
                            neibor.find(grid[row][col]) == neibor.end())
                            neibor.insert(grid[row][col]);
                    }
                    int newSize = 1;
                    for (auto&color:neibor) 
                        newSize += landsSize[color];
                    maxSize = max(maxSize, newSize);
                }
            }
        }

        return maxSize;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid;

    sol = Solution();
    grid = {{1, 0}, {0, 1}};
    cout << sol.largestIsland(grid) << endl;

    sol = Solution();
    grid = {{1, 1}, {1, 0}};
    cout << sol.largestIsland(grid) << endl;

    sol = Solution();
    grid = {{1, 1}, {1, 1}};
    cout << sol.largestIsland(grid) << endl;

    sol = Solution();
    grid = {{1, 1, 0}, {1, 0, 1}, {0, 1, 1}};
    cout << sol.largestIsland(grid) << endl;
    
    return 0;
}