/*
题目描述
输入两个链表，找出它们的第一个公共结点。
*/

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1 == NULL || pHead2 == NULL)
            return NULL;
        int l1_len = 0;
        int l2_len = 0;
        ListNode *p = pHead1;
        ListNode *q = pHead2;
        while(p != NULL)
        {
            l1_len++;
            p = p -> next;
        }
        while(q != NULL)
        {
            l2_len++;
            q = q -> next;
        }
        int pre_steps = abs(l1_len - l2_len);
        p = pHead1;
        q = pHead2;
        if(l1_len > l2_len)
        {
            for(int i = 0;i < pre_steps;i++)
            {
                p = p -> next;
            }
        }
        else
        {
            for(int i = 0;i < pre_steps;i++)
            {
                q = q -> next;
            }
        }
        while(p != NULL && q != NULL && p != q)
        {
            p = p -> next;
            q = q -> next;
        }
        return p;
    }
};