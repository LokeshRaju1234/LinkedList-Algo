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
    ListNode* swapPairs(ListNode* head) 
    {
        //if the head is null or if there is only one element then return head
       if(head == nullptr || head->next == nullptr)
       {
        return head;
       }

       ListNode* dummy = new ListNode(0);
       dummy->next = head;
       ListNode* prev = dummy;//prev will helps to swap the nodes
       ListNode* curr = head;
       
       //always check there iss two elements to swap
       while(curr != NULL && curr->next != NULL)
       {
        prev->next = curr->next;
        curr->next = prev->next->next;
        prev->next->next = curr;
        prev = curr;
        curr = curr->next;
       }

       return dummy->next;

    }
};