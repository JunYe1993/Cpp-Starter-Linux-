#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        // Kahn's Algorithm
        // http://web.ntnu.edu.tw/~algo/DirectedAcyclicGraph.html

        // adj 紀錄 node 連出去的所有 nodes
        // ref 紀錄 node 被連的次數
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> ref(numCourses, 0);
        vector<int> res;
        
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
            if (head == numCourses) return {};

            res.push_back(head);

            // 找過的 first node 要刪除, 設為 -1
            // 把這次的 first node 所連出去 nodes 的 被連次數(ref) 減一
            ref[head] = -1;
            for (auto & n : adj[head]) --ref[n];
        }

        return res;
    }
};

int main() {
    return 0;
}