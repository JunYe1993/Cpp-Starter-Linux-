#include <iostream>
#include <vector>
#include <string> 
#include <cctype>

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int size = s.size();
        string reverseAns;
        
        for (int i = size-1; i >= 0; --i) {
            if (s[i] == '-') continue;
            reverseAns.push_back(toupper(s[i]));
            if (((int)reverseAns.size()+1)%(k+1) == 0)
                reverseAns.push_back('-');    
        }
        
        // reverse
        if (reverseAns.back()=='-') reverseAns.pop_back();
        size = (int) reverseAns.size();
        for (int i = 0, j = size-1; i < j; ++i, --j) {
            char temp = reverseAns[i];
            reverseAns[i] = reverseAns[j];
            reverseAns[j] = temp;
        }

        return reverseAns;
    }
};

int main () {
    Solution sol;
    string str;
    int k;

    str = "5F3Z-2e-9-w";
    k = 4;
    cout << sol.licenseKeyFormatting(str, k) << endl;
    str = "2-5g-3-J";
    k = 2;
    cout << sol.licenseKeyFormatting(str, k) << endl;

    return 0;
}