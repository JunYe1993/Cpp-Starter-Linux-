#include <iostream>
#include <vector>
#include <map>

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
    bool hasCycleQQ(ListNode *head) {
        map<ListNode*, bool> dict;
        // vector<ListNode*> dict;
        while (head) {
            if (dict.find(head) == dict.end()) dict[head] = true;
            else return true;
            head = head->next;
        }
        return false;
    }
    // 總有一天會追上，追上有 Cycle
    bool hasCycle(ListNode *head) {
        if (!head) 
            return false;
        
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) 
                return true;
        }
        
        return false;
    }
};  

int main() {
    Solution sol;
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(2);
    ListNode n4(1);
    ListNode *ptr = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n2;
    cout << sol.hasCycle(ptr) << endl;
    
    n1.next = nullptr;
    cout << sol.hasCycle(ptr) << endl;

    return 0;
}