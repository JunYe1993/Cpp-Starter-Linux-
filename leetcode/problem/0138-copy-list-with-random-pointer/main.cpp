#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node (int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList (Node* head) {

        Node* node = head;
        
        int index = 0;
        vector<Node*> vec;
        vector<Node*> vec_copy;
        unordered_map<Node*, int> map;
        while (node) {
            vec.push_back(node);
            map[node] = index++;
            node = node->next;
        }

        if (index == 0) return nullptr;
        Node* root = new Node(0);

        node = root;
        for (int i = 0; i < index; ++i) {
            vec_copy.push_back(node);
            node->val = vec[i]->val;
            if (vec[i]->next) node->next = new Node(0);
            node = node->next;
        }

        for (int i = 0; i < index; ++i) 
            if (vec[i]->random) 
                vec_copy[i]->random = vec_copy[map[vec[i]->random]];

        return root;
    }

};

int main() {
    return 0;
}

