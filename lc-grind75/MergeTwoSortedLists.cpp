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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head;
        head->val = 0;
        *head->next = ListNode();
        ListNode* out=head->next;
        while (list1 != nullptr && list2 != nullptr) {
            int v1 = list1->val, v2 = list2->val;
            if (v1 <= v2) 
                list1 = list1->next;
            else list2 = list2->next;
            
            out->val = min(v1, v2);
            out = out->next;
            *out = ListNode();
        }
        if (list1 != nullptr)
            out->next = list1;
        if (list2 != nullptr)
            out->next = list2;
        return head->next;
    }
};

int main() {
    Solution solve;
    // cout << (solve.isValid("(){}}{") ? "yes" : "no");
}