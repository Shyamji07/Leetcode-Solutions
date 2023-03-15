class Solution {
public:
    bool isCompleteTree(TreeNode* root) 
    {
        queue<TreeNode*>q;
        bool check=0;
        bool ans=1;
        q.push(root);
        while(q.size()!=0){
            TreeNode*node=q.front();
            q.pop();
            if (check &&( node->left!=NULL || node->right!=NULL)){
                ans=0;
                break;
            }
            else if (node->left==NULL && node->right!=NULL){
                ans=0; break;
            }
                
    
            else if (node->right==NULL)
                check=1;
            
            if (node->left!=NULL)
                q.push(node->left);
            
            if (node->right!=NULL)
                q.push(node->right);
        }    
        return ans;
    }
};