#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class Solution {

    struct TypeAndCount {
        int count;
        vector<int> arr;
    };

    bool checkArr (int n, int count1, int count2) {
        return (n % 2) ? (abs(count1-count2) == 1):(count1 == count2);
    }

public:
    int movesToChessboard (vector<vector<int>>& board) {
        
        int n = board.size();
        int _1_count = 0;

        struct TypeAndCount row1 = {1, board[0]};
        struct TypeAndCount row2 = {0};
        for (int i = 1; i < n; ++i) {
            if (board[i] == row1.arr) ++row1.count;
            else if (row2.count == 0) row2 = {1, board[i]};
            else if (board[i] == row2.arr) ++row2.count;
            else return -1;
        }
        if (!checkArr(n, row1.count, row2.count)) return -1;

        struct TypeAndCount col1;
        struct TypeAndCount col2 = {0};
        
        for (int i = 0; i < n; ++i) {
            if (board[i][0]) ++_1_count;
            vector<int> temp;
            for (auto&row:board) temp.push_back(row[i]);
            if (i == 0) col1 = {1, temp};
            else {
                if (temp == col1.arr) ++col1.count;
                else if (col2.count == 0) col2 = {1, temp};
                else if (temp == col2.arr) ++col2.count;
                else return -1;
            }
        }
        if (!checkArr(n, col1.count, col2.count)) return -1;

        bool topleft = 0;
        int rowMove = 0, colMove = 0;
        for (int i = 0; i < n; ++i) {
            if (board[0][i] != topleft) ++rowMove;
            if (board[i][0] != topleft) ++colMove;
            topleft = (topleft+1)%2;
        }

        if (n % 2) {
            rowMove = (rowMove%2) ? n-rowMove:rowMove;
            colMove = (colMove%2) ? n-colMove:colMove;
        } else {
            rowMove = min(rowMove, n-rowMove);
            colMove = min(colMove, n-colMove);
        }

        return (rowMove+colMove)/2;
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> board;
    
    board = {{0,1,1,0},{0,1,1,0},{1,0,0,1},{1,0,0,1}};
    cout << sol.movesToChessboard(board) << endl;
    board = {{0,1},{1,0}};
    cout << sol.movesToChessboard(board) << endl;
    board = {{1,0},{1,0}};
    cout << sol.movesToChessboard(board) << endl;

    return 0;
}