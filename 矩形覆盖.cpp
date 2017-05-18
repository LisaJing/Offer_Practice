/*
题目描述
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
*/
class Solution {
public:
    int rectCover(int number) {
        if(number <= 2)
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