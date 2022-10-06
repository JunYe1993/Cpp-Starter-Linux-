#include<iostream>
#include<vector>
#include<string> 

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    void get_solved(Node* node, vector<vector<int>>& answer, size_t layer) {
        
        if (layer == answer.size())
            answer.push_back(vector<int>());
        
        answer[layer].push_back(node->val);
        for (auto&next:node->children)
            get_solved(next, answer, layer+1);
    }

    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>> answer;
        if (root == nullptr) 
            return answer;
        
        answer.push_back(vector<int>({root->val}));
        for (auto&next:root->children)
            get_solved(next, answer, 1);
        
        return answer;
    }
};

int main () {
    return 0;
}