#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// Rule : A[k]*2 != A[i]+A[j]
// 
// # 觀察
// 
//      1. 可以做線性變化
//            A[k]*2 + 2x  !=  A[i] + A[j] + 2x
//          > (A[k]+x) * 2 !=  (A[i]+x) + (A[j]+x)
//         
//      2. 可以做指數變化 (x != 0)
//            A[k]*2 * x   !=  (A[i]+A[j]) *x    
//          > (A[k]*x) * 2 !=  (A[i]*x) + (A[j]*x)
//      
//      3. 全奇數 BeautifulArray + 全偶數 BeautifulArray = BeautifulArray
//          > 奇奇奇 + 偶偶偶
//          > A[i]+A[j] = 奇 != A[k]*2 = 偶
// 
// 
// # Dynamic Programming
// 
//      1. A3 = [1, 3, 2] = BeautifulArray
//      2. A6_Left  = A3 * 2 - 1 = [1, 5, 3]
//      3. A6_Right = A3 * 2     = [2, 6, 4]
//      4. A6 = [1, 5, 3] + [2, 6, 4] = BeautifulArray
// 

class Solution {
public:
    vector<int> beautifulArray(int N) {
        vector<int> res = {1};
        while ((int)res.size() < N) {
            vector<int> tmp;
            for (int i : res) if (i * 2 - 1 <= N) tmp.push_back(i * 2 - 1);
            for (int i : res) if (i * 2 <= N) tmp.push_back(i * 2);
            res = tmp;
        }
        return res;
    }
};

int main() {
    Solution sol;
    int N;
    
    N = 3;
    for (auto&n:sol.beautifulArray(N))
        cout << n << " ";
    cout << endl;

    N = 4;
    for (auto&n:sol.beautifulArray(N))
        cout << n << " ";
    cout << endl;

    return 0;
}