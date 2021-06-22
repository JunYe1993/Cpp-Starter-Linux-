#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;


// Definition for singly-linked list.
typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
} ListNode;

// 題目爛，比較像取代
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

int main() {
    return 0;
}