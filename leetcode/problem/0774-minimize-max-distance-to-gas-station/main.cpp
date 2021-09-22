#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {

public:
 
    // Answers within 10^-6 of the true value will be accepted as correct.
    // 以上代表著答案可以趨近就好, 代表不用最佳解, 所以解答者使用 Binary search

    // Mid 的意義
    // mid 是對答案的猜測.
    // 第一次猜測 拿最左邊到最右邊 的中間 如果有足夠的 k 可以滿足
    // 可以滿足 (count  > k) 往下猜 => 下次猜 最左邊到mid 的中間
    // 不可滿足 (count <= k) 往上猜 => 下次猜 mid到最右邊 的中間

    // Count 的意義
    // stations =  [1,2,4,8], 猜測 (mid) = 1.3
    // [1, 2] 之間需要 0 座 (原本平均 1.0 < 1.3)
    // [2, 4] 之間需要 1 座 = [3]     平均 1.0 < 1.3 ( ceil((4-2)/1.3) - 1 = 1)
    // [4, 8] 之間需要 3 座 = [5,6,7] 平均 1.0 < 1.3 ( ceil((8-4)/1.3) - 1 = 3)

    double minmaxGasDist(vector<int>& stations, int k) {
        
        int count, N = stations.size();
        if (N == 1) return 0;
        if (N == 2) return (stations[1]-stations[0])/k;
        
        vector<int> dists;
        for (int i = 0; i < N-1; ++i) 
            dists.push_back(stations[i+1]-stations[i]);
        
        double left = 0, mid;
        double right = stations.back()-stations[0];
        while (left + 1e-6 < right) {
            mid = (left+right) / 2;
            count = 0;
            for (auto&n:dists)
                count += ceil(n/mid)-1;
            if (count > k) left = mid;
            else right = mid;
        }
        return right;
    }

    // 抄的
    double minmaxGasDistQ (vector<int>& st, int K) {
        int count, N = st.size();
        double left = 0, right = st[N - 1] - st[0], mid;
        // printf("%f\n", 1e-6);
        while (left + 1e-6 < right) {
            mid = (left + right) / 2;
            count = 0;
            for (int i = 0; i < N - 1; ++i)
                count += ceil((st[i + 1] - st[i]) / mid) - 1;
            if (count > K) left = mid;
            else right = mid;
        }
        return right;
    }
};

int main () {
    Solution sol;
    vector<int> stations;
    int k;

    k = 9, stations = {1,2,3,4,5,6,7,8,9,10};
    cout << sol.minmaxGasDist(stations, k) << endl;
    k = 1, stations = {23,24,36,39,46,56,57,65,84,98};
    cout << sol.minmaxGasDist(stations, k) << endl;
    k = 3, stations = {10,19,25,27,56,63,70,87,96,97};
    cout << sol.minmaxGasDist(stations, k) << endl;


    return 0;
}