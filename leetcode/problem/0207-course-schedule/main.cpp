#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool canFinish (int numCourses, vector<vector<int>>& prerequisites) {
        
        // Kahn's Algorithm
        // http://web.ntnu.edu.tw/~algo/DirectedAcyclicGraph.html

        // adj 紀錄 node 連出去的所有 nodes
        // ref 紀錄 node 被連的次數
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> ref(numCourses, 0);
        
        // init
        for (auto&v : prerequisites) {
            ++ref[v[0]];
            adj[v[1]].push_back(v[0]);
        }

        // Every loop 都可以找到一個 first node, 需要找出 numCourses 個
        for (int i = 0; i < numCourses; ++i) {
            
            // 一定有 node 的被連的次數為 0, 是為 first node
            // 若所有 node 被連次數都 > 0, 代表有 cycle
            int head = 0;
            while (head < numCourses && ref[head] != 0) ++head;
            if (head == numCourses) return false;

            // 找過的 first node 要刪除, 設為 -1
            // 把這次的 first node 所連出去 nodes 的 被連次數(ref) 減一
            ref[head] = -1;
            for (auto & n : adj[head]) --ref[n];
        }

        return true;
    }
};

int main() {
    Solution sol;
    int numCourses;
    vector<vector<int>> prerequisites;

    numCourses = 2;
    prerequisites = {{1,0}};
    cout << sol.canFinish(numCourses, prerequisites) << endl;
    numCourses = 3;
    prerequisites = {{1,0}, {1, 2}, {0,1}};
    cout << sol.canFinish(numCourses, prerequisites) << endl;
    numCourses = 5;
    prerequisites = {{1,4},{2,4},{3,1},{3,2}};
    cout << sol.canFinish(numCourses, prerequisites) << endl;
    numCourses = 20;
    prerequisites = {{0,10},{3,18},{5,5},{6,11},{11,14},{13,1},{15,1},{17,4}};
    cout << sol.canFinish(numCourses, prerequisites) << endl;

    return 0;
}