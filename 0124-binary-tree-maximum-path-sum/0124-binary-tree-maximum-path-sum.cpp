class Solution {
public:
    int maxi=INT_MIN;
    int dfs(TreeNode* root){
        if(!root)return 0;
        int left=max(dfs(root->left),0);
        int right=max(dfs(root->right),0);
        maxi=max(maxi,root->val+left+right);
        return max(root->val+left, root->val+right);  //we are returning single_Path_Sum and we already covered complete path sum(i.e. root->val+left+right ) in line number 8;
        
    }
    int maxPathSum(TreeNode* root) {
        if(!root)return 0;
        dfs(root);
        return maxi;
    }
};