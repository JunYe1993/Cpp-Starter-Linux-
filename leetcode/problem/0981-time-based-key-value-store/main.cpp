#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

class TimeMap {
    unordered_map<string, vector<pair<int, string>>> map;
public:
    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        map[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {

        if (map.find(key) == map.end())
            return "";

        int l  = 0;
        int r = map[key].size();
        while (l < r) {
            int mid = (l+r)/2;
            if (map[key][mid].first <= timestamp)
                l = mid + 1;
            else
                r = mid;
        }

        return (r == 0) ? "":map[key][r-1].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main () {

    return 0;
}