#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <unordered_map>
#include <bits/stdc++.h>

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
    int getDecimalValue (ListNode* head) {
        int ret = 0;
        while (head) {
            ret = ret * 2 + head->val;
            head = head->next;
        }
        return ret;
    }
};

int main() {
    return 0;
}