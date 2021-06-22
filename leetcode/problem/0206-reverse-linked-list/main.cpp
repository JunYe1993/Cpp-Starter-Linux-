#include<iostream>
#include<string>
#include<vector>
#include<map>

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
    ListNode* reverseListQ(ListNode* head) {
        vector<ListNode*> temp;
        ListNode root;
        ListNode *ptr = &root;
        while (head) {
            temp.push_back(head);
            head = head->next;
        }
        while (!temp.empty()) {
            ptr->next = temp.back();
            ptr = ptr->next;
            temp.pop_back();
        }
        ptr->next = nullptr;
        return root.next;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode *nextNode, *prevNode = nullptr;
        while (head) {
            nextNode = head->next;
            head->next = prevNode;
            prevNode = head;
            head = nextNode;
        }
        return prevNode;
    }
};

int main() {
    ListNode root(-1), a(1), b(2), c(3), d(4), e(5);
    root.next = &a;
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    Solution sol;
    ListNode *p = sol.reverseList(root.next);
    while (p){
        cout << p->val << " ";
        p = p->next;
    } 
    cout << endl;
    return 0;
}