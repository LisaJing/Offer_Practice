/*
题目描述
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int pre_size = pre.size();
        int vin_size = vin.size();
        if(pre_size <= 0 || vin_size <= 0 || pre_size != vin_size)
            return NULL;
        TreeNode *root = BuildTreeHelper(pre, vin, 0, pre_size - 1, 0 , vin_size - 1);
        return root;
    }
    TreeNode * BuildTreeHelper(vector<int> &pre, vector<int> &vin, int pre_start, int pre_end, int vin_start, int vin_end)
    {
        if(pre_start > pre_end || vin_start > vin_end || pre_end - pre_start != vin_end - vin_start)
            return NULL;
        TreeNode *root = new TreeNode(pre[pre_start]);
        cout << root -> val << endl;
        int i = vin_start;
        for(; i <= vin_end; i++)
        {
            if(vin[i] == pre[pre_start])
                break;
        }
        int left_size = i - vin_start + 1;
        root -> left = BuildTreeHelper(pre, vin, pre_start + 1, pre_start + left_size - 1, vin_start, i - 1);
        root -> right = BuildTreeHelper(pre, vin, pre_start + left_size, pre_end, i + 1, vin_end);
        return root;
    }
};