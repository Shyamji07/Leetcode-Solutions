class Solution {
public:
    int sum =0;
    int solve(TreeNode* root,int ans){
        if(!root)return 0;
        ans=ans*10 + root->val;
        if(!root->left&&!root->right)sum+=ans;
        int left=solve(root->left,ans);
        int right=solve(root->right,ans);
        
        return ans;
    }
    int sumNumbers(TreeNode* root) {
        int ans=0;
        solve(root,ans);
        return sum;
    }
};