/*
题目描述
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
假设压入栈的所有数字均不相等。
例如序列1,2,3,4,5是某栈的压入顺序，
序列4，5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。
（注意：这两个序列的长度是相等的）
*/

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int push_size = pushV.size();
        int pop_size = popV.size();
        if(push_size == 0 || pop_size == 0 || push_size != pop_size)
            return false;
        stack<int> Vstack;
        vector<int>::iterator vit1 = pushV.begin();
        vector<int>::iterator vit2 = popV.begin();
        Vstack.push(*vit1);
        vit1++;
        while(!Vstack.empty() && vit2 != popV.end() )
        {
            while(!Vstack.empty() && Vstack.top() == *vit2)
            {
                Vstack.pop();
                vit2++;
            }
             
            if(!Vstack.empty() && vit2 != popV.end() && vit1 == pushV.end())
            {
                return false;
            }
             
            if(vit1 != pushV.end())
            {
                Vstack.push(*vit1);
                vit1++;
            }
             
        }
        if(Vstack.empty() && vit2 != popV.end())
            return false;
        return true;
    }
     
};