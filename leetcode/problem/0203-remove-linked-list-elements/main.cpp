#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements (ListNode* head, int val) {
        
        ListNode* root = new ListNode(0, head);
        ListNode* pre = root;
        
        while (head) {
            if (head->val != val) pre = head;
            else pre->next = head->next;
            head = head->next;
        }
        return root->next;
    }
};

int main() { return 0; }