/*
输入一个链表，从尾到头打印链表每个节点的值。
*/

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        if(head == NULL)
            return res;
        ListNode *new_head = reverseList(head);
        while(new_head != NULL)
        {
            res.push_back(new_head -> val);
            new_head = new_head -> next;
        }
        return res;
    }
     
    ListNode * reverseList(ListNode *head)
    {
        if(head == NULL || head -> next == NULL)
            return head;
        ListNode *p = head;
        ListNode *q = head -> next;
        p -> next = NULL;
        while(q != NULL)
        {
            ListNode *r = q -> next;
            q -> next = p;
            p = q;
            q = r;
        }
        return p;
    }
};