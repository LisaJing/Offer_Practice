/*
题目描述
输入两棵二叉树A，B，判断B是不是A的子结构。
（ps：我们约定空树不是任意一个树的子结构）
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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1 == NULL || pRoot2 == NULL)
            return false;
        if(pRoot1 -> val == pRoot2 -> val && isSubStructure(pRoot1,pRoot2))
            return true;
        if(pRoot1 -> left != NULL && pRoot1 -> left -> val == pRoot2 -> val && isSubStructure(pRoot1 -> left,pRoot2))
            return true;
        if(pRoot1 -> right != NULL && pRoot1 -> right -> val == pRoot2 -> val && isSubStructure(pRoot1 -> right,pRoot2))
            return true;
        return false;
    }
     
    bool isSubStructure(TreeNode *p1, TreeNode *p2)
    {
        if(p2 == NULL)
            return true;
        if(p1 == NULL)
            return false;
        if(p1 -> val == p2 -> val)
            return isSubStructure(p1 -> left, p2 -> left) && isSubStructure(p1 -> right, p2 -> right);
        else
            return false;
    }
};