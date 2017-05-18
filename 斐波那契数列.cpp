/*
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
n<=39
*/
class Solution {
public:
    int Fibonacci(int n) {
        if(n == 0 || n == 1)
            return n;
        int n1 = 0;
        int n2 = 1;
        for(int i = 2;i <= n;i++)
        {
            int tmp = n1 + n2;
            n1 = n2;
            n2 = tmp;
        }
        return n2;
    }
};

