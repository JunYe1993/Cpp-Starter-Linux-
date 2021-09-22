#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

int read4 (char* buf) {
    return 4;
}

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    string r_chars;
    int r_num = 0;
    int read (char *buf, int n) {
        
        int read = 0;
        if (r_num > 0) {
            if (r_num <= n) {
                int i = 0;
                for (; i < r_num; ++i) buf[i] = r_chars[i];
                r_chars = "";
                r_num = 0;
                read = i;       
            } else {
                for (int i = 0; i < n; ++i) buf[i] = r_chars[i];
                r_chars = r_chars.substr(n, r_num-n);
                r_num = r_num-n;
                return n;
            }
        }

        while (read < n) {
            char buf4[4];
            int num = read4(buf4);
            if (num == 0) break;
            int i = 0;
            for (; i < num && read+i < n; ++i)
                buf[read+i] = buf4[i];
            
            for (; i < num; ++i, ++r_num)
                r_chars.push_back(buf4[i]);
            

            read = min(read+num, n);
        }

        return read;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    return 0;
}