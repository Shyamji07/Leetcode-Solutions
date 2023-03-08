/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()){
            size_t n = q.size();
            vector<int> tmp;
            for(int i=0;i<n;i++)
            {
                TreeNode* t = q.front();
                q.pop();
                if(t){
                    tmp.push_back(t->val);
                }
                 if(t->left)q.push(t->left);
                 if(t->right)q.push(t->right);

            }
            if(tmp.size()>0)
            res.push_back(tmp);
        }

            reverse(res.begin(),res.end());
        return res;
    }
};