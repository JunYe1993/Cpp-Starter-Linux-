#include <iostream>
#include <vector>
#include <string> 
#include <sstream>

using namespace std;

class Solution {
    struct updateData {
        int startIndex;
        int endIndex;
        int val;
        updateData(vector<int>&x):startIndex(x[0]), endIndex(x[1]), val(x[2]) {}
    };
public:

    // 優化解 : 先把加總結果都計算出來
    vector<int> getModifiedArray (int length, vector<vector<int>>& updates) {
        
        // 如何紀錄加總結果 ？
        //
        // 假設 length = 5, updates = {{1,3,2},{2,3,3}};
        // 紀錄 {1,3,2} => [0,2,0,0,-2]
        // 在結算時 
        //  1. 遇到  2 (index = 1) 時代表往後都放 +2 進去
        //  2. 遇到 -2 (index = 3) 時代表往後都放 -2 進去
        // 達到 {1,3,2} 的結果
        // 
        // 再紀錄 {2,3,3} => [0,0,3,0,-3] 結合之前的紀錄 => [0,2,3,0,-5]
        // Answer = [0, 2, 5, 5, 0]

        // 紀錄加總結果
        vector<int> arr(length, 0);
        for (auto&raw:updates) {
            struct updateData data(raw);
            arr[data.startIndex] += data.val;
            if (data.endIndex+1 == length) continue;
            arr[data.endIndex+1] -= data.val;
        }

        cout << "Why Broke" << endl;

        // 計算
        int curNumber = 0;
        for (auto&n:arr) {
            n += curNumber;
            curNumber = n;
        }
        
        return arr;
    }

    // 暴力解 : 會每個 index 都計算一次
    vector<int> getModifiedArrayQ (int length, vector<vector<int>>& updates) {
        
        vector<int> arr(length, 0);
        for (auto&raw:updates) {
            struct updateData data(raw);
            for (int i = data.startIndex; i <= data.endIndex; ++i)
                arr[i] += data.val;
        }

        return arr;
    }
};

int main () {
    Solution sol;
    int length;
    vector<vector<int>> updates;

    length = 5, updates = {{1,3,2},{2,4,3},{0,2,-2}};
    for (auto&n:sol.getModifiedArray(length, updates))
        cout << n << " ";
    cout << endl;
    length = 10, updates = {{2,4,6},{5,6,8},{1,9,-4}};
    for (auto&n:sol.getModifiedArray(length, updates))
        cout << n << " ";
    cout << endl;

    return 0;
}