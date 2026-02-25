/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!= NULL && fast->next != nullptr)
        {
            slow  = slow->next;
            fast = fast->next->next;

            if(slow == fast)
            {
                slow = head;
                while(slow != fast)//if they meet again the meet point is where cycle begins
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return {};
    }
};