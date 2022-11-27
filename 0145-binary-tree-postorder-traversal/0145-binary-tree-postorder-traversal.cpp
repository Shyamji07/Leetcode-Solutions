class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>answer;
        stack<TreeNode*> s;
        TreeNode* currentNode=NULL;
        if(root==NULL)
            return answer;
        s.push(root);
        while(!s.empty()){
             currentNode= s.top();
            s.pop();
            answer.push_back(currentNode->val);
            if(currentNode->left!=NULL)
                s.push(currentNode->left);
            
            if(currentNode->right!=NULL)
                s.push(currentNode->right);
        }
        reverse(answer.begin(),answer.end());
        return answer;
        
        
    }
};