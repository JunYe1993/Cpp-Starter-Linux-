#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

#define INT_MAX 2147483647

using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
        unordered_map<char, int> count;
        count['b'] = 0;
        count['a'] = 0;
        count['l'] = 0;
        count['o'] = 0;
        count['n'] = 0;
        for (auto&c:text)
            if (count.find(c) != count.end())
                ++count[c];
        
        count['l'] /= 2;
        count['o'] /= 2;
        int answer = INT_MAX;
        for (auto&n:count)
            answer = min(answer, n.second);

        return answer;
    }
};

int main() {
    Solution sol;
    string text;

    text = "nlaebolko";
    cout << sol.maxNumberOfBalloons(text) << endl;
    text = "loonbalxballpoon";
    cout << sol.maxNumberOfBalloons(text) << endl;
    text = "leetcode";
    cout << sol.maxNumberOfBalloons(text) << endl;

    return 0;
}