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
        printListHelper(res, head);
        return res;
    }
    void printListHelper(vector<int> &res, ListNode* head)
    {
        if(head == NULL)
            return;
        
        printListHelper(res, head -> next);
        res.push_back(head -> val);
    }
};