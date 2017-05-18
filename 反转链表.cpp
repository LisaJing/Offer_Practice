/*
题目描述
输入一个链表，反转链表后，输出链表的所有元素
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
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == NULL || pHead -> next == NULL)
            return pHead;
        ListNode *p = pHead;
        ListNode *q = pHead -> next;
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