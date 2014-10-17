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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        
        ListNode *fast = head;
        ListNode *slow = head;
        
        for(int i = 0; i < n; i++)
        {
            fast = fast->next;
        }
        if(fast == NULL) return slow->next;
        while(fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        
        return head;
    }
};
