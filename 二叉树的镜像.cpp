/*
题目描述
操作给定的二叉树，将其变换为源二叉树的镜像。 
输入描述:
二叉树的镜像定义：源二叉树 
            8
           /  \
          6   10
         / \  / \
        5  7 9 11
        镜像二叉树
            8
           /  \
          10   6
         / \  / \
        11 9 7  5

*/


/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
          
        pRoot = GetMirror(pRoot);
    }
      
    TreeNode *GetMirror(TreeNode *pRoot)
    {
        if(pRoot == NULL)
            return NULL;
        if(pRoot -> left == NULL && pRoot -> right == NULL)
            return pRoot;
        if(pRoot -> left == NULL)
        {
            pRoot -> left = GetMirror(pRoot -> right);
            pRoot -> right = NULL;
            return pRoot;
        }
        if(pRoot -> right == NULL)
        {
            pRoot -> right = GetMirror(pRoot -> left);
            pRoot -> left = NULL;
            return pRoot;
        }
        TreeNode *leftTmp = GetMirror(pRoot -> right);
        TreeNode *rightTmp = GetMirror(pRoot -> left);
        pRoot -> left = leftTmp;
        pRoot -> right = rightTmp;
        return pRoot;
    }
      
};