//Recursive Approach

class Solution { 
public:
    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return v;
    }
    vector<int> v;
    void postorder(TreeNode* root)
    {
        if(root==NULL)return;
        postorder(root->left);
        postorder(root->right);
        v.push_back(root->val);
    }
};


// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int>answer;
//         stack<TreeNode*> s;
//         TreeNode* currentNode=NULL;
//         if(root==NULL)
//             return answer;
//         s.push(root);
//         while(!s.empty()){
//              currentNode= s.top();
//             s.pop();
//             answer.push_back(currentNode->val);
//             if(currentNode->left!=NULL)
//                 s.push(currentNode->left);
            
//             if(currentNode->right!=NULL)
//                 s.push(currentNode->right);
//         }
//         reverse(answer.begin(),answer.end());
//         return answer;
        
        
//     }
// };