/*
题目描述
定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
*/

class Solution {
public:
    void push(int value) {
        if(s1.empty())
        {
            s1.push(value);
            s2.push(value);
        }
        else
        {
            s1.push(value);
            if(value <= s2.top())
                s2.push(value);
        }
    }
     
    void pop() {
        if(s1.empty())
            return;
        if(s1.top() == s2.top())
            s2.pop();
        s1.pop();
    }
     
     
    int top() {
        if(s1.empty())
            return -1;
        return s1.top();
    }
    int min() {
        if(s2.empty())
            return -1;
        return s2.top();
    }
private:
    stack<int> s1;
    stack<int> s2;
};