#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    string orderlyQueue(string s, int k) {
        
        if (k > 1) {
            // k = 2 就可以做 bubble sort
            sort(s.begin(), s.end());

        } else {
            int size = s.size();
            vector<int> minIndexs;
            minIndexs.push_back(0);
            for (int i = 1; i < size; ++i) {
                if (s[i] == s[minIndexs.back()])
                    minIndexs.push_back(i);
                else if (s[i] < s[minIndexs.back()]) {
                    minIndexs.clear();
                    minIndexs.push_back(i);
                }
            }

            int length = 0;
            while (minIndexs.size()>1) {
                ++length;
                if (length == size) break;
                vector<int> temp = {minIndexs[0]};
                for (int i = 1; i < (int)minIndexs.size(); ++i) {
                    int min = (temp.back() + length)%size;
                    int cur = (minIndexs[i]+ length)%size;
                    if (s[cur] == s[min]) 
                        temp.push_back(minIndexs[i]);
                    else if (s[cur] < s[min]) {
                        temp.clear();
                        temp.push_back(minIndexs[i]);
                    }
                }
                minIndexs = temp;
            }

            // cout << minIndexs[0] << endl;
            s = s.substr(minIndexs[0], size-minIndexs[0]) + s.substr(0, minIndexs[0]);
        }

        return s;
    }
};

int main() {
    Solution sol;
    string str;
    int k;

    str = "cba";  
    k = 1;
    cout << sol.orderlyQueue(str, k) << endl;
    str = "baaca";
    k = 3;
    cout << sol.orderlyQueue(str, k) << endl;
    str = "xmvzi";
    k = 2;
    cout << sol.orderlyQueue(str, k) << endl;
    
    return 0;
}