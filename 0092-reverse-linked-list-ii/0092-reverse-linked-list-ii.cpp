/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == nullptr || left == right) return head; //if l = r the we cant reverse one element so we return head
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;//prev will helps when reversal starts at first
        for(int i = 1;i < left;i++)
        {
            prev = prev->next;//keeping prev just before the left sublist 
        }

        ListNode* curr = prev->next;
        ListNode* next = NULL;

        for(int i = 0;i < right - left;i++)
        {
            next = curr->next;
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }
        return dummy->next;
    }
};