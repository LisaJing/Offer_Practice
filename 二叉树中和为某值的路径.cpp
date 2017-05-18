/*
题目描述
输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int> > paths;
        if(root == NULL)
            return paths;
        vector<int> path;
        int curSum = 0;
        findPaths(root,expectNumber,curSum,path,paths);
        return paths;
    }
     
    void findPaths(TreeNode *root, int expectNumber, int curSum, vector<int> path,vector<vector<int> > & paths)
    {
        if(root == NULL)
            return;
        curSum += root -> val;
        path.push_back(root -> val);
        if(root -> left == NULL && root -> right == NULL)
        {
            if(curSum == expectNumber)
                paths.push_back(path);
            return;
        }      
         
        findPaths(root -> left, expectNumber, curSum,path,paths);
        findPaths(root -> right, expectNumber, curSum,path,paths);
         
    }
     
};