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
    ListNode* plusOne(ListNode* head) {
        if(head == NULL)return head;
        stack<ListNode*> s;
        for(ListNode* tmp = head; tmp != NULL; tmp = tmp->next)
        {
            s.push(tmp);
        }
        
        int carry = 1;
        while(!s.empty())
        {
            ListNode* top = s.top();
            s.pop();
            if(top->val + carry >= 10)
            {
                top->val = top->val + carry - 10;
                carry = 1;
            }
            else
            {
                top->val += carry;
                carry = 0;
            }
        }
        
        if(carry == 1)
        {
            ListNode* tmp = new ListNode(1);
            tmp->next = head;
            return tmp;
        }
        return head;
    }
};