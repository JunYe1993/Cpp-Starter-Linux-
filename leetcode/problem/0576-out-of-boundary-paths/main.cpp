#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int x;
    int y;
    Point(int x, int y) : x(x), y(y) {}
};

class Solution {
    int maxRow, maxCol, mod = 1000000007;
    int rowMove[4] = { 1, 0, 0,-1 };
    int colMove[4] = { 0, 1,-1, 0 };
    vector<vector<vector<int>>> dp;
    vector<vector<int>> cells;
    void setBoundaryCell(int m, int n) {
        cells = vector<vector<int>>(m, vector<int>(n, 0));
        maxRow = m;
        maxCol = n;
        for (int i = 0; i < n; ++i) {
            ++cells[0][i];
            ++cells[m-1][i];
        }
        for (int i = 0; i < m; ++i) {
            ++cells[i][0];
            ++cells[i][n-1];
        }
    } 
    bool validMove(int row, int col) {
        return (0 <= row && row < maxRow && 0 <= col && col < maxCol);
    }
    void setDP (int m, int n, int maxMove) {
        dp = vector<vector<vector<int>>>(maxMove+1, vector<vector<int>>(m, vector<int>(n, -1)));
        dp[1] = vector<vector<int>>(m, vector<int>(n, 0));
        maxRow = m;
        maxCol = n;
        for (int i = 0; i < maxCol; ++i) {
            ++dp[1][0][i];
            ++dp[1][m-1][i];
        }
        for (int i = 0; i < maxRow; ++i) {
            ++dp[1][i][0];
            ++dp[1][i][n-1];
        }
    }
public:
    // top -> down
    int findPathsBFS(int m, int n, int maxMove, int startRow, int startColumn) {
        // 這是暴力解(Brute Force) BFS，
        // 有個缺點使之無法完善，要一直算到 maxMove 才會有結果。
        // 中間有重複也無法做儲存做 DP 解。
        setBoundaryCell(m, n);
        queue<Point> q;
        int paths = 0;
        q.push(Point(startRow, startColumn));
        for (int i = 0; i < maxMove; ++i) {
            queue<Point> temp;
            while (!q.empty()) {
                Point p = q.front();
                paths += cells[p.x][p.y];
                // cout << "x = " << p.x << ", y = " << p.y << endl;
                for (int j = 0; j < 4; ++j) {
                    int x = p.x + rowMove[j];
                    int y = p.y + colMove[j];
                    if (validMove(x, y))
                        temp.push(Point(x,y));
                }
                q.pop();
            }
            // cout << "-------------------`" << endl;
            q = temp;
        }
        return paths;
    }
    int DFS (int row, int col, int leftMove) {
        if (leftMove == 1) return dp[leftMove][row][col];
        if (dp[leftMove][row][col] != -1) {
            //cout << "It worked" << endl;
            return dp[leftMove][row][col] % mod;
        }
        
        int ret = dp[1][row][col];
        for (int i = 0; i < 4; ++i) {
            if (validMove(row+rowMove[i], col+colMove[i])) {
                ret += DFS (row+rowMove[i], col+colMove[i], leftMove-1);
                ret %= mod;
            }
        }
        dp[leftMove][row][col] = ret;
        return ret % mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if (maxMove < 1) return 0;
        setDP (m, n, maxMove);
        return DFS (startRow, startColumn, maxMove);
    }
};

int main() {
    Solution sol;
    int m, n, maxMove, startRow, startCol;

    m = 2; n = 2;
    maxMove = 2;
    startRow = 0;
    startCol = 0;
    cout << sol.findPaths(m, n, maxMove, startRow, startCol) << endl;

    m = 1; n = 3;
    maxMove = 3;
    startRow = 0;
    startCol = 1;
    cout << sol.findPaths(m, n, maxMove, startRow, startCol) << endl;

    m = 8; n = 7;
    maxMove = 16;
    startRow = 1;
    startCol = 5;
    cout << sol.findPaths(m, n, maxMove, startRow, startCol) << endl;

    return 0;
}