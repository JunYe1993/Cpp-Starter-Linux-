#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * 
 */

class Robot {
  public:
    // Returns true if the cell in front is open and robot moves into the cell.
    // Returns false if the cell in front is blocked and robot stays in the current cell.
    bool move();
    // Robot will stay in the same cell after calling turnLeft/turnRight.
    // Each turn will be 90 degrees.
    void turnLeft();
    void turnRight();
    // Clean the current cell.
    void clean();
};

class Solution {
private:
    // unordered_map<int, unordered_map<int, bool>> visited;
    vector<vector<bool>> visited;
    vector<vector<pair<int, int>>> dir = {
        {{ 1, 0}, { 0,-1}, {-1, 0}, { 0, 1}}, // Left
        {{ 0,-1}, {-1, 0}, { 0, 1}, { 1, 0}}, // Up
        {{-1, 0}, { 0, 1}, { 1, 0}, { 0,-1}},
        {{ 0, 1}, { 1, 0}, { 0,-1}, {-1, 0}}
    };

    void cleanRoom (Robot& robot, int x, int y, int direction) {
        
        visited[x][y] = true;
        robot.clean();

        robot.turnLeft();
        vector<pair<int, int>>& thisDir = dir[direction];
        direction = (direction == 0) ? 3 : direction-1;
        int dirs = (x == 0 && y == 0) ? 4 : 3;
        for (int i = 0; i < dirs; ++i) {
            int nextx = x + thisDir[i].first;
            int nexty = y + thisDir[i].second;
            if (!visited[nextx][nexty] && robot.move()) {
                cleanRoom (robot, nextx, nexty, direction);
                robot.move();
                robot.turnLeft();
                robot.turnLeft();
            }
            robot.turnRight();
            direction = (direction+1)%4;
        }
    }

public:
    void cleanRoom (Robot& robot) {
        visited = vector<vector<bool>>(200, vector<bool>(400, false));
        cleanRoom (robot, 0, 0, 1);
    }
};

int main () {
    return 0;
}