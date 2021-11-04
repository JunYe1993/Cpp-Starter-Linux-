#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution {
    int row, col;
    vector<pair<int, int>> await;
    vector<pair<int, int>> fourDir = {
        { 1, 0},
        {-1, 0},
        { 0, 1},
        { 0,-1}
    };

    void BFS (vector<vector<char>>& board, int x, int y) {

        board[x][y] = 'o';
        int curAwaitSize = (int) await.size();
        await.push_back({x, y});

        bool needFlip = true;
        queue<pair<int, int>> q;
        q.push({x, y});
        while (!q.empty()) {
            for (auto&d:fourDir) {
                int xx = q.front().first  + d.first;
                int yy = q.front().second + d.second;
                if (isValid(xx, yy) && board[xx][yy] == 'O') {
                    board[xx][yy] = 'o';
                    await.push_back({xx, yy});
                    if (isEdge(xx, yy)) needFlip = false;
                    else q.push({xx, yy});
                }
            }
            q.pop();
        }

        // showAwait();
        if (needFlip) {
            int size = await.size();
            for (int i = curAwaitSize; i < size; ++i)
                board[await[i].first][await[i].second] = 'X';
            await.resize(curAwaitSize);
        }
        // showAwait();
        // showBoard(board);
    }

    bool isValid (int x, int y) {
        return (x>=0 && x<row && y>=0 && y<col);
    }

    bool isEdge (int x, int y) {
        return (x==0 || x==row-1 || y==0 || y==col-1);
    }

    void showAwait () {
        if (await.empty()) cout << "Empty";
        for (auto&a:await) {
            printf ("%d, %d\n", a.first, a.second);
        }
        cout << endl;
    }

public:
    void solve (vector<vector<char>>& board) {
        
        row = board.size();
        col = board[0].size();
        for (int i = 1; i < row-1; ++i)
            for (int j = 1; j < col-1; ++j)
                if (board[i][j] == 'O') 
                    BFS (board, i, j);

        while (!await.empty()) {
            board[await.back().first][await.back().second] = 'O';
            await.pop_back();
        }
    }

    void showBoard (vector<vector<char>>& board) {
        for (auto&v:board) {
            for (auto&c:v)
                cout << c << " ";
            cout << endl;
        }
    }
};

int main() {
    Solution sol;
    vector<vector<char>> board;

    board = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    sol.showBoard(board);
    sol.solve(board);
    sol.showBoard(board);

    board = {{'X'}};
    sol.showBoard(board);
    sol.solve(board);
    sol.showBoard(board);

    return 0;
}