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
    bool isPalindromeQQQ(ListNode* head) {
        vector<int> arr;
        while (head != nullptr) {
            arr.push_back(head->val);
            head = head->next;
        }
        int size = arr.size();
        for(int i = 0, j = size-1; i < j; ++i,--j)
            if (arr[i] != arr[j])
                return false;
        return true;
    }
    bool isPalindrome(ListNode* head) {
        
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // 轉向後半段
        ListNode *prev = nullptr, *temp;
        while (slow) {
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        fast = head;
        slow = prev;
        while (slow) {
            if (fast->val != slow->val) 
                return false;
            else {
                fast = fast->next;
                slow = slow->next;
            }
        }
        return true;
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
    cout << sol.isPalindrome(ptr) << endl;
    
    n2.next = nullptr;
    cout << sol.isPalindrome(ptr) << endl;

    return 0;
}