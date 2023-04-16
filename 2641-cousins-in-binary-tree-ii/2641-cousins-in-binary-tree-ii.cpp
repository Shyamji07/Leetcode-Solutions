class Solution {
    int s[100005];
    void dfs(TreeNode* root,int d)
    {
        s[d]+=root->val;
        if(root->left!=nullptr)dfs(root->left,d+1);
        if(root->right!=nullptr)dfs(root->right,d+1);
    }
    void work(TreeNode* root,int d,int t)
    {
        if(root==nullptr)return;
        root->val=s[d]-root->val-t;
        int tl=root->left==nullptr?0:root->left->val,tr=root->right==nullptr?0:root->right->val;
        work(root->left,d+1,tr);
        work(root->right,d+1,tl);
    }
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        dfs(root,0);
        work(root,0,0);
        return root;
    }
};