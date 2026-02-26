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

        //looping for right - left tims because only int window r - l + 1 the starting ele in sublist moves to right and only remaining elements changes their positions
        for(int i = 0;i < right - left;i++)
        {
            next = curr->next; //always point next pointer after curr
            curr->next = next->next;//remove the next element's link becuase it moves before of this curr
            next->next = prev->next;//move the next element before of curr
            prev->next = next;//at last link prev to the newly moved element
        }
        return dummy->next;
    }
};