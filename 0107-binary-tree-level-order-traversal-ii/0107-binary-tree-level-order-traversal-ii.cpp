class Solution {
public:
//     vector<vector<int>> levelOrderBottom(TreeNode* root) {
//         vector<vector<int>> res;
//         if(!root) return res;
//         queue<TreeNode *> q;
//         q.push(root);

//         while(!q.empty()){
//             size_t n = q.size();
//             vector<int> tmp;
//             for(int i=0;i<n;i++)
//             {
//                 TreeNode* t = q.front();
//                 q.pop();
//                 if(t){
//                     tmp.push_back(t->val);
//                 }
//                  if(t->left)q.push(t->left);
//                  if(t->right)q.push(t->right);

//             }
//             if(tmp.size()>0)
//             res.push_back(tmp);
//         }

//             reverse(res.begin(),res.end());
//         return res;
//     }
    
    void levelOrder(vector<vector<int>> &ans, TreeNode *node, int level) {
        if (!node) return;
        if (level >= ans.size())
            ans.push_back({});
        ans[level].push_back(node->val);
        levelOrder(ans,node->left,level+1);
        levelOrder(ans,node->right,level+1);
}

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        levelOrder(ans,root,0);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};