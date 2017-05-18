/*
题目描述
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则输出Yes,否则输出No。
假设输入的数组的任意两个数字都互不相同。
*/

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        int size = sequence.size();
        if(size <= 0)
            return false;
        return isValidSequence(sequence, 0, size - 1);
 
    }
    bool isValidSequence(vector<int> &sequence,int begin, int end)
    {
        if(end <= begin)
            return true;
        int cur_num = sequence[end];
        int i = begin;
        for(;i < end;i++)
        {
            if(cur_num < sequence[i])
                break;
        }
        int left_end = i - 1;
        int right_start = i;
        if(isValidSequence(sequence, begin, left_end) )
        {
            i = right_start;
            for(;i < end;i++)
            {
                if(cur_num >= sequence[i])
                    return false;
            }
            return isValidSequence(sequence, right_start, end - 1);
        }
        else
            return false;
         
    }
};