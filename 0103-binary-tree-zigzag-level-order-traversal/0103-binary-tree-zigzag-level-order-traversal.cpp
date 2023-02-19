class Solution {
public:
     vector<vector<int>>ans;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return {};
        deque<TreeNode *>q;
        q.push_front(root);
        int level = 0;
        while(!q.empty()){
            int sz = q.size();
            vector<int>tmp;
            for(int i = 0 ; i < sz; i++){
                if(level%2 != 0){
                    TreeNode *temp = q.front();
                    q.pop_front();
                    tmp.push_back(temp->val);
                    if(temp->right){
                        q.push_back(temp->right);
                    }
                    if(temp->left){
                        q.push_back(temp->left);
                    }
                }else{
                    TreeNode *temp = q.back();
                     tmp.push_back(temp->val);
                    q.pop_back();
                    if(temp->left){
                        q.push_front(temp->left);
                    }
                    if(temp->right){
                        q.push_front(temp->right);
                    }
                }
            }
            if(tmp.size() > 0){
                ans.push_back(tmp);
            }
            level++;
        }
        return ans;
        
    }
};

// class Solution { //SOLN 2
// public:
//      vector<vector<int>>ans;
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//         if(!root)return {};
//         stack <TreeNode*>s1,s2;
//         s1.push(root);
//         vector<int>v;
//         bool ltr=true;
//         while(!s1.empty()){
//             int sz=s1.size();
//                 while(sz--){
//                     TreeNode* temp=s1.top();
//                     s1.pop();
//                     if(ltr){
//                         v.push_back(temp->val);
//                         if(temp->left)s2.push(temp->left);
//                         if(temp->right)s2.push(temp->right);
//                     }
//                     if(!ltr){
//                         v.push_back(temp->val);
//                         if(temp->right)s2.push(temp->right);
//                         if(temp->left)s2.push(temp->left);
//                     }
//                 }
//                 ans.push_back(v);
//                 v.clear();
//             ltr=!ltr;
//                 s1=s2;
//                 while(!s2.empty()){
//                     s2.pop();
//                 }
//             }
//         return ans;
     
//     }
// };