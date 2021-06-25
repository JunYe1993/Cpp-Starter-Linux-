#include <iostream>
#include <algorithm>
#include <vector>

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        
        ListNode root = ListNode(0);
		ListNode *ptr = &root;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                ptr->next = l1;
                ptr = ptr->next;
                if (l1->next == nullptr) {
                    ptr->next = l2;
                    break;
                } else 
                    l1 = l1->next;
            } else {
                ptr->next = l2;
                ptr = ptr->next;
                if (l2->next == nullptr) {
                    ptr->next = l1;
                    break;
                } else 
                    l2 = l2->next;
            }
        } 
        return root.next;
    }
};

int main() {
    Solution sol;
    ListNode v1_1(1), v2_1(1);
    ListNode v1_2(2), v2_2(3);
    ListNode v1_3(4), v2_3(4);
    ListNode *ptr1 = &v1_1, *ptr2 = &v2_1;
    v1_1.next = &v1_2;
    v1_2.next = &v1_3;
    v2_1.next = &v2_2;
    v2_2.next = &v2_3;
    sol.mergeTwoLists(ptr1, ptr2);
    return 0;
}