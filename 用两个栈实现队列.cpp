/*
题目描述
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
*/
class Solution
{
public:
    void push(int node) {
        stack2.push(node);
        if(stack1.empty())
        {
            while(!stack2.empty())
            {
                stack1.push(stack2.top());
                stack2.pop();
            }
        }
    }
 
    int pop() {
        if(stack1.empty() && stack2.empty())
            return -1;
        if(stack1.empty())
        {
            while(!stack2.empty())
            {
                stack1.push(stack2.top());
                stack2.pop();
            }
        }
        int res = stack1.top();
        stack1.pop();
        return res;
    }
 
private:
    stack<int> stack1;
    stack<int> stack2;
};