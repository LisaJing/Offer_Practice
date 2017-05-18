/*
题目描述
一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
*/
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int size = data.size();
        if(size <= 1)
            return;
        int tmp = 0;
        for(int i = 0;i < size;i++)
        {
            tmp ^= data[i];
        }
        int theBitOf1 = 0;
        while((tmp & 0x1) != 1)
        {
            theBitOf1++;
            tmp >>= 1;
        }
        vector<int> a1;
        vector<int> a2;
        for(int i = 0;i < size;i++)
        {
            if(((data[i] >> theBitOf1) & 0x1)== 1)
                a1.push_back(data[i]);
            else
                a2.push_back(data[i]);
        }
        (*num1) = 0;
        (*num2) = 0;
        for(vector<int>::iterator vit = a1.begin(); vit != a1.end();vit++)
        {
            (*num1) ^= (*vit);
        }
        for(vector<int>::iterator vit = a2.begin(); vit != a2.end();vit++)
        {
            (*num2) ^= (*vit);
        }
    }
};