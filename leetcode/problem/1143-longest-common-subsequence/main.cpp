#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {

    void swap (string& text1, string& text2) {
        string temp = text1;
        text1 = text2;
        text2 = temp;
    }

    void showVector (vector<int>& v) {

        for (auto&n : v)
            cout << n << " ";
        cout << endl;
    }

public:
    int longestCommonSubsequence (string text1, string text2) {
        
        if (text1.empty() || text2.empty()) return 0;
        if (text1.size() < text2.size()) swap (text1, text2);
        int size1 = text1.size();
        int size2 = text2.size();
        
        for (int i = 0; i < size1; ++i) {
            for (int j = 0; j < size2; ++j) {
                
            }
        }


    }
};

int main() {
    Solution sol;
    string text1, text2;

    text1 = "acebcde";
    text2 = "ace";
    cout << sol.longestCommonSubsequence (text1, text2) << endl;

    return 0;
}