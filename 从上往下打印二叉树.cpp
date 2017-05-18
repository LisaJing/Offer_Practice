/*
题目描述
从上往下打印出二叉树的每个节点，同层节点从左至右打印。
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        if(root == NULL)
            return res;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *tmp = q.front();
            q.pop();
            if(tmp -> left != NULL)
                q.push(tmp -> left);
            if(tmp -> right != NULL)
                q.push(tmp -> right);
            res.push_back(tmp -> val);
        }
        return res;
    }
  private:
    queue<TreeNode *> q;
};