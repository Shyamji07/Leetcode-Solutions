#define pi pair<int,int>
class Solution {
public:
    pi robUtil(TreeNode* root)
    {
        if(!root)
            return {0,0};
        pi p1=robUtil(root->left);
        pi p2=robUtil(root->right);
        
        int include=root->val+p1.second+p2.second;
        int exclude=max(p1.first,p1.second)+max(p2.first,p2.second);
        return {include,exclude};
    }
    int rob(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        pi p1=robUtil(root);
        return max(p1.first,p1.second);
    }
};