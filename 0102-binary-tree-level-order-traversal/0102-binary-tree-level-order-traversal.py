class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>v;
        if(root ==NULL)return v;
        queue<TreeNode * >q;
        q.push(root);
        while(!q.empty()){
            vector<int>temp;
            int n=q.size();
            while(n--){
                TreeNode *t =q.front();
                temp.push_back(t->val);
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
                q.pop();
            }
            v.push_back(temp);
        }
        return v;
    }
};