#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findOriginalArray(vector<int> changed) {
        
        int size = changed.size();
        if (size % 2) return {};
        
        int index = 0;
        sort(changed.begin(), changed.end());
        vector<int> answer = {changed[0]};
        // for (int&num:changed)
        //     cout << num << " ";
        // cout << endl;

        for (int i = 1; i < size; ++i) {

            if (index == (int)answer.size()) {
                // cout << "1" << endl;
                answer.push_back(changed[i]);
                if ((int)answer.size() > (size/2))
                    return {};
            
            } else if (changed[i] == answer[index]*2) {
                // cout << "2" << endl;
                if (++index > (size/2))
                    return {};

            } else {
                // cout << "3" << endl;
                answer.push_back(changed[i]);
                if ((int)answer.size() > (size/2))
                    return {};
            }
        }
        return answer;
    }
};

int main() {
    Solution sol;

    for (int&num:sol.findOriginalArray({1,3,4,2,6,8}))
        cout << num << " ";
    cout << endl;
    
    for (int&num:sol.findOriginalArray({6,3,0,1}))
        cout << num << " ";
    cout << endl;

    
    for (int&num:sol.findOriginalArray({1}))
        cout << num << " ";
    cout << endl;

    return 0;
}