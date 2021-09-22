#include <iostream>
#include <vector>
#include <string> 
#include <sstream>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);
        string tempstr;

        vector<int> stack = {1};
        bool doneTree = false;
        while (getline(ss, tempstr, ',')) {
            if (doneTree) return false;
            if (tempstr != "#") stack.push_back(2);
            else {
                --stack.back();
                while (stack.back() == 0) {
                    stack.pop_back();
                    if (stack.empty()) {
                        doneTree = true;
                        break;
                    }
                    --stack.back();
                }
            }
        }
        return stack.empty();
    }

    bool isValidSerializationQQ (string preorder) {

        vector<string> str;
        stringstream ss(preorder);
        string s;
        while (getline(ss, s, ','))
            str.push_back(s);

        vector<int> stack = {1};
        bool doneTree = false;
        for ( auto&s : str ) {
            if (doneTree) return false;
            if (s != "#") stack.push_back(2);
            else {
                --stack.back();
                while (stack.back() == 0) {
                    stack.pop_back();
                    if (stack.empty()) {
                        doneTree = true;
                        break;
                    }
                    --stack.back();
                }
            }
        }

        return stack.empty();
    }
};

int main () {
    Solution sol;
    string preorder;

    preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    cout << sol.isValidSerialization(preorder) << endl;
    preorder = "1,#";
    cout << sol.isValidSerialization(preorder) << endl;
    preorder = "9,#,#,1";
    cout << sol.isValidSerialization(preorder) << endl;
    preorder = "#,#";
    cout << sol.isValidSerialization(preorder) << endl;
    preorder = "#";
    cout << sol.isValidSerialization(preorder) << endl;

    return 0;
}