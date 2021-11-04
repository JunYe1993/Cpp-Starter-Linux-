#include<iostream>
#include<map>
#include<vector>

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
    ListNode* addTwoNumbers (ListNode* l1, ListNode* l2) {

        ListNode* root = l1;
        int carry = 0;
        
        while ( l1 || l2 || carry > 0 ) {
            
            int sum = carry;
            sum += (l1) ? l1->val : 0;
            sum += (l2) ? l2->val : 0;

            l1->val = sum % 10;
            carry   = sum / 10;

            if ( ((l2 && l2->next) || carry > 0) && !l1->next) l1->next = new ListNode();
            l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return root;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    ListNode* node;

    ListNode root1 = ListNode();
    nums = {9, 9, 9, 9, 9, 9, 9};
    // nums = {2, 4, 3};
    node = &root1;
    for (auto&n:nums) {
        node->next = new ListNode();
        node->next->val = n;
        node = node->next;
    }

    ListNode root2 = ListNode();
    nums = {9, 9, 9, 9};
    // nums = {5, 6, 4};
    node = &root2;
    for (auto&n:nums) {
        node->next = new ListNode();
        node->next->val = n;
        node = node->next;
    }
    
    node = sol.addTwoNumbers(root1.next, root2.next);
    while (node) {
        cout << node->val << " ";
        node = node->next;
    }
        
    cout << endl;

    return 0;
}