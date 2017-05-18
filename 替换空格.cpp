/*
请实现一个函数，将一个字符串中的空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/
class Solution {
public:
    void replaceSpace(char *str,int length) {
        if(str == NULL || length <= 0)
            return;
        char *p = str;
        int count_space = 0;
        int cur_loc = 0;
        while(cur_loc < length)
        {
            if(str[cur_loc] == ' ')
                count_space++;
            cur_loc++;
        }
        if(count_space <= 0)
            return;
        int new_length = length + 2 * count_space;
        int i = new_length - 1;
        int j = length - 1;
        while(i >= 0 && j >= 0 && i > j)
        {
            if(str[j] == ' ')
            {
                str[i--] = '0';
                str[i--] = '2';
                str[i--] = '%';
                j--;
            }
            else
            {
                str[i--] = str[j--];
            }
        }
    }
};