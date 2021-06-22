#include<iostream>
#include<vector>
#include<set>

using namespace std;

class Solution {
public:
    bool isRowValid(vector<vector<char>>& board) {
        set<char> checker;
        for (auto&row:board) {
            
            checker.clear();
            for (auto&c:row) {
                if (c == '.') 
                    continue;
                else {
                    if (checker.find(c) == checker.end()) checker.insert(c);
                    else return false;
                }
            }
        }
        return true;
    }
    bool isColValid(vector<vector<char>>& board) {
        set<char> checker;
        for (size_t i = 0; i < 9; ++i) {
            checker.clear();
            for (size_t j = 0; j < 9; ++j) {
                char &c = board[j][i];
                if (c == '.')
                    continue;
                else {
                    if (checker.find(c) == checker.end()) checker.insert(c);
                    else return false;
                }
            }
        }
        return true;
    }
    bool isBoxValid(vector<vector<char>>& board) {
        set<char> checker;
        for (size_t i = 0; i < 9; ++i) {
            checker.clear();
            for (size_t j = 0; j < 9; ++j) {
                char &c = board[(i/3)*3+(j/3)][(i%3)*3+(j%3)];
                if (c == '.')
                    continue;
                else {
                    if (checker.find(c) == checker.end()) checker.insert(c);
                    else return false;
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        return isRowValid(board) && isColValid(board) && isBoxValid(board);
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<char>> board;

    board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    cout << sol.isValidSudoku(board) << endl;

    board = {
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    cout << sol.isValidSudoku(board) << endl;

    board = {
        {'.','.','.','.','5','.','.','1','.'},
        {'.','4','.','3','.','.','.','.','.'},
        {'.','.','.','.','.','3','.','.','1'},
        {'8','.','.','.','.','.','.','2','.'},
        {'.','.','2','.','7','.','.','.','.'},
        {'.','1','5','.','.','.','.','.','.'},
        {'.','.','.','.','.','2','.','.','.'},
        {'.','2','.','9','.','.','.','.','.'},
        {'.','.','4','.','.','.','.','.','.'}
    };
    cout << sol.isValidSudoku(board) << endl;

    return 0;
}