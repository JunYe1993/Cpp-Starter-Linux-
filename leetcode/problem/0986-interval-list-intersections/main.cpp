#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection (vector<vector<int>>& A, vector<vector<int>>& B) {

        vector<vector<int>> res;
        int sizeA = A.size();
        int sizeB = B.size();
        
        for (int i = 0, j = 0; i < sizeA && j < sizeB;) {
            
            // has interval
            if (A[i][1] >= B[j][0] && B[j][1] >= A[i][0])
                res.push_back({max(A[i][0], B[j][0]), min(A[i][1], B[j][1])});

            (A[i][1] > B[j][1]) ? ++j : ++i;
        }
        
        return res;
    }
};

int main () {
    
    Solution sol;
    vector<vector<int>> firstList, secondList;

    firstList  = {{0,2},{5,10},{13,23},{24,25}};
    secondList = {{1,5},{8,12},{15,24},{25,26}};
    for (auto&v:sol.intervalIntersection(firstList, secondList))
        printf("(%2d, %2d) ", v[0], v[1]);
    cout << endl;
    firstList  = {{1,3},{5,9}};
    secondList = {};
    for (auto&v:sol.intervalIntersection(firstList, secondList))
        printf("(%2d, %2d) ", v[0], v[1]);
    cout << endl;
    firstList  = {};
    secondList = {{4,8},{10,12}};
    for (auto&v:sol.intervalIntersection(firstList, secondList))
        printf("(%2d, %2d) ", v[0], v[1]);
    cout << endl;
    firstList  = {{1,7}};
    secondList = {{3,10}};
    for (auto&v:sol.intervalIntersection(firstList, secondList))
        printf("(%2d, %2d) ", v[0], v[1]);
    cout << endl;


    return 0;
}