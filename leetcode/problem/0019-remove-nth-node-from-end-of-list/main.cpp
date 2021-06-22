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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head)
            return nullptr;

        ListNode root(-1);
        root.next = head;

        ListNode *slow = &root;
        ListNode *fast = &root;

        for (int i = 0; i < n; i++)
            fast = fast->next;

        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode *to_be_deleted = slow->next;
        slow->next = slow->next->next;
        delete to_be_deleted;

        return root.next;
    }
};

int main() {
    return 0;
}