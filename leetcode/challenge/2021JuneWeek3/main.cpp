#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) return {};
        vector<int> used = {1};
        vector<int> sum = {1};
        vector<string> ret = {"("};
        
        for (int loop = 0; loop < n*2-1; ++loop) 
        {
            for (size_t i = 0; i < ret.size(); ++i) 
            {
                string temp;
                //cout << "add ) ..." << endl;
                // add )
                if (sum[i] > 0) {
                    temp = ret[i];
                    ret[i] = temp + ")";
                    --sum[i];
                }
                //cout << "add ( ..." << endl;
                // add (
                if (used[i] < n) {
                    if (temp.empty()) {
                        ret[i] += "(";
                        ++sum[i];
                        ++used[i];
                    } else {
                        ret.push_back(temp + "(");
                        sum.push_back(sum[i]+2);
                        used.push_back(used[i]+1);
                    }
                }
            }
        }
        return ret;
    }
};

int main() {
    Solution sol = Solution();
    
    // Test1
    int nums = 3;
    vector<string> answer = sol.generateParenthesis(nums);
    for (auto &s:answer)
        cout << s << endl;

    return 0;
}