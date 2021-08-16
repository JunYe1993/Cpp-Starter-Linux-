#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
    struct point {
        int x;
        int y;
        int value;
    };
    int find (vector<int>& sets, int index) {
        // 負數代表指向自己, 其值為 -Rank
        return sets[index] < 0 ? index : sets[index] = find(sets, sets[index]);
    }
    void unionProcess (vector<struct point>& sameNums, vector<int>& rowRank, vector<int>& colRank, vector<vector<int>>& matrix) {

        // init union
        int mSize = rowRank.size();
        int nSize = colRank.size();
        vector<int> sets = vector<int>(mSize+nSize, -1);
        
        for (auto&num:sameNums) {
            int px = find(sets, num.x);
            int py = find(sets, mSize + num.y);
            if (px != py) {
                sets[py] = min(sets[px], sets[py]);
                sets[py] = min(sets[py], -max(rowRank[num.x], colRank[num.y])-1);
                sets[px] = py; // x 指向 y
            }
        }

        // put unions rank on matrix
        for (auto&num:sameNums) {

            // cout << "Cur value = " << num.value << endl;
            int rank = sets[find(sets, mSize+num.y)]*-1;
            rowRank[num.x] = rank;
            colRank[num.y] = rank;
            matrix[num.x][num.y] = rank;

            // for (auto i = 0; i < mSize; ++i) {
            //     for (auto j = 0; j < nSize; ++j) {
            //         if (i == num.x && j == num.y)
            //             printf("[%3d] ", matrix[i][j]);
            //         else
            //             printf("%5d ", matrix[i][j]);
            //     }
            //     cout << endl;
            // }
            // cout << endl;
        }
    }

public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        
        // 嘗試用過自己寫的 sort => TLE. ( 打不贏就加入 ) 
        int mSize = matrix.size();
        int nSize = matrix[0].size();
        vector<struct point> ranks;
        for (int i = 0; i < mSize; ++i)
            for (int j = 0; j < nSize; ++j)
                ranks.push_back({i, j, matrix[i][j]});

        sort (ranks.begin(), ranks.end(), [](struct point &a, struct point &b){ return a.value < b.value;});

        vector<int> rowRank(mSize, 0);
        vector<int> colRank(nSize, 0);
        vector<struct point> sameNums;
        matrix = vector<vector<int>>(mSize, vector<int>(nSize, 0));
        for (auto&p:ranks) {
            // cout << "cur p value = " << p.value << endl;
            if (sameNums.empty() || sameNums.back().value == p.value) 
                sameNums.push_back(p);
            else {            
                // for (auto&ss:sameNums)
                //     printf("%3d ", ss.value);
                // cout << endl;

                unionProcess(sameNums, rowRank, colRank, matrix);
                sameNums.clear();
                sameNums.push_back(p);
            }
        }

        unionProcess(sameNums, rowRank, colRank, matrix);
        return matrix;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix;

    matrix = {{20,-21,14},{-19,4,19},{22,-47,24},{-19,4,19}};
    matrix = {{7,7}, {7,7}};
    matrix = {{2,3,1},{9,4,5},{3,4,2}};
    matrix = {{-2,-35,-32,-5,-30,33,-12},{7,2,-43,4,-49,14,17},{4,23,-6,-15,-24,-17,6},{-47,20,39,-26,9,-44,39},{-50,-47,44,43,-22,33,-36},{-13,34,49,24,23,-2,-35},{-40,43,-22,-19,-4,23,-18}};

    for (auto&v:sol.matrixRankTransform(matrix)) {
        for (auto&n:v)
            printf("%3d ", n);
        cout << endl;
    }
    
    return 0;
}