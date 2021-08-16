#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        
        unordered_set<string> unique;

        for (auto& email: emails) {

            auto pivot  = email.find('@');
            auto user   = email.substr(0, pivot);
            auto domain = email.substr(pivot + 1);

            // for .
            for (size_t i = 0; i < user.size(); ) {
                if (user[i] == '.') {
                    if (i+1 == user.size()) user.erase(i);
                    else user.erase(i, 1);
                } else 
                    ++i;
            }

            // for +
            auto i = user.find('+');
            if (i != string::npos)
                user = user.substr(0, i);
            
            unique.insert(user + '@' + domain);
        }
        return unique.size();
    }
};

int main() {
    Solution sol;
    vector<string> emails;

    emails = {
        "test.email+alex@leetcode.com",
        "test.e.mail+bob.cathy@leetcode.com",
        "testemail+david@lee.tcode.com"
    };
    cout << sol.numUniqueEmails(emails) << endl;

    emails = {
        "a@leetcode.com",
        "b@leetcode.com",
        "c@leetcode.com"
    };
    cout << sol.numUniqueEmails(emails) << endl;

    return 0;
}