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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
        ListNode *aboveLeft = nullptr;
        ListNode *exactLeft;
        ListNode *aboveRight;
        ListNode *ptr = head;
        
        int index = 1;
        while (index++ < left) {
            aboveLeft = ptr;
            ptr = ptr->next;
        }
        exactLeft = ptr;

        --index;
        while (index++ < right)
            ptr = ptr->next;
        aboveRight = ptr->next;
        ptr->next = nullptr;
        
        if (aboveLeft != nullptr) {
            aboveLeft->next = reverseList(exactLeft);
            exactLeft->next = aboveRight;
            return head;
        } else {
            aboveLeft = reverseList(exactLeft);
            exactLeft->next = aboveRight;
            return aboveLeft;
        }
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
    ListNode *p = sol.reverseBetween(root.next, 1, 4);
    while (p){
        cout << p->val << " ";
        p = p->next;
    } 
    cout << endl;
    return 0;
}