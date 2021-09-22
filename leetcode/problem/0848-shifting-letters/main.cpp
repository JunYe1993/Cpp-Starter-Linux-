#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        
        int size = s.size();      
        for (int i = size - 1; i >= 0; --i) { 
            shifts[i] %= 26;
            if (i + 1 != size) 
                shifts[i] = (shifts[i] + shifts[i+1]) % 26;
            s[i] = ((s[i]-'a'+shifts[i])%26) + 'a';
        }

        return s;
    }
    string shiftingLetters(string S, vector<int> sh) {
        for (int i = sh.size() - 1, m = 0; i >= 0; --i, m %= 26)
            S[i] = ((S[i] - 'a') + (m += sh[i])) % 26 + 'a';
        return S;
    }
};

int main() {
    Solution sol;
    string str;
    vector<int> shifts;

    str = "abc";
    shifts = {3,5,9};
    cout << sol.shiftingLetters(str, shifts) << endl;
    str = "aaa";
    shifts = {1,2,3};
    cout << sol.shiftingLetters(str, shifts) << endl;
    
    return 0;
}