#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
    bool BFS (string& s, string& e, unordered_map<string, vector<pair<string, double>>> map, vector<double>& res) {
        
        if (map.find(s) == map.end()) return false;
        if (s == e) {
            res.push_back(1.0);
            return true;
        }
        queue<pair<string, double>> q;
        q.push({s, 1.0});
        while (!q.empty()) {
            pair<string, double> cur = q.front();
            q.pop();
            for (auto&next:map[cur.first]) {
                if (next.second < 0) continue;
                if (next.first == e) {
                    res.push_back(cur.second*next.second);
                    return true;
                }
                next.second *= cur.second;
                q.push(next);
                next.second = -1.0;
            }
        }
        return false;

    }

public:
    vector<double> calcEquation (vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        unordered_map<string, vector<pair<string, double>>> map;
        int size = equations.size();
        for (int i = 0; i < size; ++i) {
            map[equations[i][0]].push_back({equations[i][1], values[i]});
            map[equations[i][1]].push_back({equations[i][0], 1/values[i]});
        }

        vector<double> res;
        for (auto&v:queries)
            if (!BFS(v[0], v[1], map, res))
                res.push_back(-1.0);
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<string>> equations, queries;
    vector<double> values;
    
    equations = {{"a","b"},{"b","c"}};
    values    = {2.0, 3.0};
    queries   = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
    for (auto&d:sol.calcEquation(equations, values, queries)) 
        cout << d << " ";
    cout << endl;
    equations = {{"a","b"},{"b","c"},{"bc","cd"}};
    values    = {1.5,2.5,5.0};
    queries   = {{"a","c"},{"c","b"},{"bc","cd"},{"cd","bc"}};
    for (auto&d:sol.calcEquation(equations, values, queries)) 
        cout << d << " ";
    cout << endl;
    equations = {{"a","b"}};
    values    = {0.5};
    queries   = {{"a","b"},{"b","a"},{"a","c"},{"x","y"}};
    for (auto&d:sol.calcEquation(equations, values, queries)) 
        cout << d << " ";
    cout << endl;

    return 0;
}