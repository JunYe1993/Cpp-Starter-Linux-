#include<iostream>
#include<vector>
#include<string>

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

    void showLists (vector<ListNode*>& lists) {
        cout << "@@@";
        for (auto&p:lists)
            if (p)
                cout << p->val << " ";
        cout << endl;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode root;
        ListNode *cur = &root;

        while (!lists.empty()) {
            
            if (lists.size() == 1) {
                cur->next = lists[0];
                return root.next;
            } else {
                int index = -1;
                for (int i = 0; i < (int)lists.size(); ) {
                    if (lists[i] == nullptr)
                        lists.erase(lists.begin()+i);
                    else {
                        if (index == -1 || lists[i]->val < lists[index]->val) {
                            cur->next = lists[i];
                            index = i;
                        }
                        ++i;
                    }
                }

                if (lists.empty() || index < 0) break;
                else {
                    if (lists[index]->next) lists[index] = lists[index]->next;
                    else lists.erase(lists.begin()+index);
                }
                cur = cur->next;
            }
        }

        return root.next;
    }
};

int main() {

    Solution sol;
    ListNode* root;
    vector<ListNode*> lists;

    ListNode l1(1);
    ListNode l1n(4);
    ListNode l1nn(5);
    l1.next  = &l1n;
    l1n.next = &l1nn;
    ListNode l2(1);
    ListNode l2n(3);
    ListNode l2nn(4);
    l2.next  = &l2n;
    l2n.next = &l2nn;
    ListNode l3(2);
    ListNode l3n(6);
    l3.next  = &l3n;
    lists = {&l1, &l2, &l3};
    root = sol.mergeKLists(lists);
    while (root) {
        cout << root->val << " ";
        root = root->next;
    }
    cout << endl;

    /*ListNode l1(1);
    lists = {nullptr, nullptr};
    root = sol.mergeKLists(lists);
    while (root) {
        cout << root->val << " ";
        root = root->next;
    }
    cout << endl;*/

    return 0;
}