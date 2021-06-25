#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    //!< O(size(subseq))
    bool isMatchingSubseq (const string &s, const string &subseq) {
        size_t pos = 0;
        
        for (char c : subseq) {
            pos = s.find_first_of(c, pos);
            if (pos++ == string::npos) {
                return false;
            }
        }
        return true;
    }
public:
    //!< Iterate over the vector, check each string
    int numMatchingSubseq (string s, vector<string>& words) {
        int result = 0;
        for (string &subseq : words) {
            if (isMatchingSubseq(s, subseq)) {
                result++;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    string str;
    vector<string> words;

    str = "abcde";
    words = {"a","bb","acd","ace","acd"};
    cout << sol.numMatchingSubseq(str, words) << endl;

    str = "dsahjpjauf";
    words = {"ahjpjau","ja","ahbwzgqnuk","tnmlanowax"};
    cout << sol.numMatchingSubseq(str, words) << endl;
    return 0;
}