/*
题目描述
输入一个链表，输出该链表中倒数第k个结点。
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead == NULL || k <= 0)
            return NULL;
        ListNode *p =pListHead;
        ListNode *q = pListHead;
        int i = 0;
        while(i < k && p != NULL)
        {
            p = p -> next;
            i++;
        }
        if(p == NULL && i < k)
            return NULL;
        if(p == NULL)
            return q;
         
        while(p != NULL)
        {
            p = p -> next;
            q = q -> next;
        }
        return q;
    }
};