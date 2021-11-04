#include <iostream>
#include <vector>
#include <string> 

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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        vector<int> recieves(k, 0);
        vector<ListNode*> res;
        
        int count = 0;
        ListNode *tail = head;
        while (tail) {
            ++count;
            tail = tail->next;
        }

        int average = count/k;
        int remains = count%k;
        for (int i = 0; i < k; ++i)
            recieves[i] = (i < remains) ? average+1:average;

        for (auto&r:recieves) {
            if (r > 0) {
                res.push_back(head);
                for (int i = 0; i < r-1; ++i) head = head->next;
                ListNode* temp = head->next;
                head->next = nullptr;
                head = temp;
            } 
        }
        res.resize(k);

        return res;
    }
};

int main () {
    return 0;
}