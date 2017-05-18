/*
题目描述
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
*/

class Solution {
public:
    double Power(double base, int exponent) {
        if(base == 0)
        {
            if(exponent == 0)
                return 1;
            else
                return 0;
        }
        if(base == 1)
            return 1;
        if(exponent == 1)
            return base;
        if(exponent == 0)
            return 1;
        double res = 0.0;
        bool flag = true;
        if(exponent < 0)
        {
            flag = false;
            exponent = - exponent;
        }
        if(exponent & 0x1)
        {
            double tmp = Power(base, exponent / 2);
            res = tmp * tmp * base;
        }
        else
        {
            double tmp = Power(base, exponent / 2);
            res = tmp * tmp;           
        }
        if(!flag)
            res = 1.0 / res ;
        return res;
           
    }
};