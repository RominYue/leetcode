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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode * p1,*p2,*head,*ptr ;
        p1 = l1; p2 = l2;
        int is_add = 0, tmp;
        head = ptr = new ListNode(0);
        while(p1 != NULL || p2 != NULL)
        {
            if(p1 != NULL && p2 != NULL)
            {
                tmp = p1 ->val + p2 ->val + is_add;
                p1 = p1 ->next;
                p2 = p2 ->next;
            }
            else if(p1 != NULL)
            {
                tmp = p1 ->val +is_add;
                p1 = p1 ->next;
            }
            else if(p2 != NULL)
            {
                tmp = p2 ->val + is_add;
                p2 = p2 ->next;
            }
            is_add = 0;
            if(tmp > 9)
            {
                tmp -= 10;
                is_add = 1;
            }
            ListNode *tmpnode = new ListNode(tmp);
            ptr ->next = tmpnode;
            ptr = tmpnode;
        }
        if(is_add)ptr->next= new ListNode(is_add);
        return head ->next;
    }
};
