/*
题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/

class Solution {
public:
    int jumpFloor(int number) {
        if(number <= 0 || number == 1 || number == 2)
            return number;
        int n1 = 1;
        int n2 = 2;
        for(int i = 3;i <= number;i++)
        {
            int tmp = n1 + n2;
            n1 = n2;
            n2 = tmp;
        }
        return n2;
    }
};