/*
题目描述
在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int row_size = array.size();
        if(row_size <= 0)
            return false;
        int col_size = array[0].size();
        if(col_size <= 0)
            return false;
        int i = 0;
        int j = col_size - 1;
        while(i < row_size && j >= 0)
        {
            if(array[i][j] == target)
                return true;
            else if(array[i][j] < target)
                i++;
            else
                j--;
        }
        return false;
    }
};