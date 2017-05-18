/*
题目描述
输入一个整数数组，实现一个函数来调整该数组中数字的顺序:
使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，
并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int size = array.size();
        if(size <= 1)
            return;
        int odd_end = size - 1;
        int even_end = size - 1;
        while(odd_end >= 0)
        {
            while((array[odd_end] & 0x1) == 0) //find odd
            {
                odd_end--;
            }
            if(odd_end <= 0)
                return;
              
            even_end = odd_end - 1;
            while((even_end >= 0) && ((array[even_end] & 0x1) != 0)) //find even
            {
                even_end--;
            }
            if(even_end < 0)
                return;
            std::swap(array[even_end], array[odd_end]);
             
            //reverse 1
            int tmp_odd_end = odd_end - 1;
            int tmp_odd_index2 = even_end + 1;
            while(tmp_odd_index2 < tmp_odd_end)
            {
                std::swap(array[tmp_odd_end], array[tmp_odd_index2]);
                tmp_odd_end--;
                tmp_odd_index2++;
            }
             
             
            //reverse 2
            tmp_odd_end = odd_end - 1;
            int tmp_odd_index = even_end;
          
            while(tmp_odd_index < tmp_odd_end)
            {
                std::swap(array[tmp_odd_end], array[tmp_odd_index]);
                tmp_odd_end--;
                tmp_odd_index++;
            }
             
            odd_end--;
              
        }
    }
};