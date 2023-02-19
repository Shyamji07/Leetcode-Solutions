class Solution {
public:
     vector<vector<int>>ans;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return {};
        stack <TreeNode*>s1,s2;
        s1.push(root);
        vector<int>v;
        bool ltr=true;
        while(!s1.empty()){
            int sz=s1.size();
                while(sz--){
                    TreeNode* temp=s1.top();
                    s1.pop();
                    if(ltr){
                        v.push_back(temp->val);
                        if(temp->left)s2.push(temp->left);
                        if(temp->right)s2.push(temp->right);
                    }
                    if(!ltr){
                        v.push_back(temp->val);
                        if(temp->right)s2.push(temp->right);
                        if(temp->left)s2.push(temp->left);
                    }
                }
                ans.push_back(v);
                v.clear();
            ltr=!ltr;
                s1=s2;
                while(!s2.empty()){
                    s2.pop();
                }
            }
        return ans;
     
    }
};