#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {

public:
    int reachableNodes (vector<vector<int>>& edges, int maxMoves, int n) {
        
        // init map
        unordered_map<int, unordered_map<int, int>> refmap;
        for (auto v : edges) refmap[v[0]][v[1]] = refmap[v[1]][v[0]] = v[2];

        vector<int> minDistance(n, -1);
        minDistance[0] = 0;
        
        priority_queue<pair<int, int>> q;
        q.push({0, 0});
        while (q.size()) {
            int node = q.top().first;
            int move = q.top().second;
            q.pop();  
            
            for (auto&next:refmap[node]) {
                int n_node = next.first;
                int n_move = move + next.second + 1;
                if (minDistance[n_node] < 0 || minDistance[n_node] > n_move) {
                    minDistance[n_node] = n_move;
                    q.push({n_node, n_move});
                }
            }
        }

        int answer = 0;
        vector<bool> visited(n, false);
        for (auto&e:edges) {
            int u = minDistance[e[0]];
            int v = minDistance[e[1]];
            int fromU = (u < 0 || u > maxMoves) ? -1:((maxMoves >= u + e[2]) ? e[2]: maxMoves-u);
            int fromV = (v < 0 || v > maxMoves) ? -1:((maxMoves >= v + e[2]) ? e[2]: maxMoves-v);
            if (fromU == -1 && fromV == -1) continue;
            int this_e = 0;
            this_e += (fromU < 0) ? 0 : fromU;
            this_e += (fromV < 0) ? 0 : fromV;
            answer += min(this_e, e[2]);
            answer += (fromU >= 0 && !visited[e[0]]) ? 1:0;
            answer += (fromV >= 0 && !visited[e[1]]) ? 1:0;
            visited[e[0]] = visited[e[1]] = true;
        }

        return (answer > 0) ? answer:1;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges;
    int maxMoves, n;

    edges = {{0,1,10},{0,2,1},{1,2,2}};  
    maxMoves = 6, n = 3;
    cout << sol.reachableNodes (edges, maxMoves, n) << endl;
    edges = {{0,1,4},{1,2,6},{0,2,8},{1,3,1}};  
    maxMoves = 10, n = 4;
    cout << sol.reachableNodes (edges, maxMoves, n) << endl;
    edges = {{1,2,4},{1,4,5},{1,3,1},{2,3,4},{3,4,5}};  
    maxMoves = 17, n = 5;
    cout << sol.reachableNodes (edges, maxMoves, n) << endl;
    edges = {{0,2,0},{1,3,1},{0,1,0},{1,4,0},{0,4,0},{2,4,4},{2,3,6},{0,3,8},{3,4,1},{1,2,4}};
    maxMoves = 4, n = 5;
    cout << sol.reachableNodes (edges, maxMoves, n) << endl;
    
    return 0;
}