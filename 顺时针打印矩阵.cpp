/*题目描述
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字.
例如，如果输入如下矩阵： 
1 2 3 4 
5 6 7 8 
9 10 11 12 
13 14 15 16 
则依次打印出数字:
1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*/

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
        int row_size = matrix.size();
        if(row_size <= 0)
            return res;
        int col_size = matrix[0].size();
        if(col_size <= 0)
            return res;
        printMatrixCircle(matrix, res, 0, 0, row_size - 1, col_size - 1);
        return res;
    }
    void printMatrixCircle(vector<vector<int> > & matrix, vector<int> & res,int left_up_row, int left_up_col, int right_down_row, int right_down_col)
    {
        if(left_up_row > right_down_row || left_up_col > right_down_col)
            return;
        if(left_up_row == right_down_row)
        {
            for(int m = left_up_col;m <= right_down_col;m++)
                res.push_back(matrix[left_up_row][m]);
            return;
        }
         
        if(left_up_col == right_down_col)
        {
            for(int m = left_up_row;m <= right_down_row;m++)
                res.push_back(matrix[m][left_up_col]);
            return;
        }
         
         
        int i = left_up_row;
        int j = left_up_col;
         
        //1 : left to right
         
        while(j <= right_down_col)
        {
            res.push_back(matrix[i][j]);
            j++;
        }
        //2 : up to down
        if(j > right_down_col)
        {
            j--;
            i++;
        }
        while(i <= right_down_row)
        {
            res.push_back(matrix[i][j]);
            i++;
        }
        //3 : right to left
        if( i > right_down_row)
        {
            i--;
            j--;
        }
        while( j >= left_up_col)
        {
            res.push_back(matrix[i][j]);
            j--;
        }
        //4 : down to up
        if(j < left_up_col)
        {
            i--;
            j++;
        }
        while(i > left_up_row)
        {
            res.push_back(matrix[i][j]);
            i--;
        }
         
        left_up_row++;
        left_up_col++;
        right_down_row--;
        right_down_col--;
        printMatrixCircle(matrix, res, left_up_row, left_up_col, right_down_row, right_down_col);
         
             
    }
     
};