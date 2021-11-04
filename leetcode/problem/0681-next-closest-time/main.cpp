#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <set>

using namespace std;

class Solution {

    string getFormat (int HH, int MM) {
        string HHstr = (HH/10) ? to_string(HH):"0"+to_string(HH);
        string MMstr = (MM/10) ? to_string(MM):"0"+to_string(MM);
        return HHstr + ":" + MMstr;
    }

public:
    string nextClosestTime (string time) {
        
        int HH, MM;
        auto pos = time.find(':');
        sscanf(time.substr(0, pos).c_str(), "%d", &HH);
        sscanf(time.substr(pos+1, time.size()-pos-1).c_str(), "%d", &MM);
        
        set<int> digits;
        for (auto&d:time)
            if (d != ':')
                digits.insert(d-'0');

        // HH-M(M)
        int minDigit = *(digits.begin());
        for (auto&d:digits) {
            int curMM = (MM/10)*10 + d;
            if (curMM > MM) 
                return getFormat(HH, curMM);
        }
        // HH-(M)M
        for (auto&d:digits) {
            int curMM = d*10 + minDigit;
            if (curMM > MM && curMM < 60) 
                return getFormat(HH, curMM);
        }       

        // H(H)-MM
        int minMM = minDigit;
        minMM += (MM/10) ? minDigit*10:0;
        for (auto&d:digits) {
            int curHH = (HH/10)*10 + d;
            if (curHH > HH && curHH < 24) 
                return getFormat(curHH, minMM);
        }

        // (H)H-MM
        for (auto&d:digits) {
            int curHH = d*10+minDigit;
            if (curHH > HH && curHH < 24)
                return getFormat(curHH, minMM);
        }

        int minHH = minDigit;
        minHH += (HH/10) ? minDigit*10:0;
        return getFormat(minHH, minMM);
    }
};

int main() {
    Solution sol;
    string time;

    time = "19:34";
    cout << sol.nextClosestTime(time) << endl;
    time = "23:59";
    cout << sol.nextClosestTime(time) << endl;

    return 0;
}