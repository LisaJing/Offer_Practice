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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == NULL)
            return pHead2;
        if(pHead2 == NULL)
            return pHead1;
        ListNode *p = pHead1;
        ListNode *q = pHead2;
        ListNode *l3 = new ListNode(0);
        ListNode *r = l3;
        while(p != NULL || q != NULL)
        {
            int p_val = (p != NULL ? p -> val : INT_MAX);
            int q_val = (q != NULL ? q -> val : INT_MAX);
            int val =  std::min(p_val, q_val);
            ListNode *newnode = new ListNode(val);
            r -> next = newnode;
            r = newnode;
            if(val == p_val)
                p = p -> next;
            else if(val == q_val)
                q = q -> next;
        }
        ListNode *res = l3 -> next;
        delete l3;
        l3 = NULL;
        return res;
    }
};