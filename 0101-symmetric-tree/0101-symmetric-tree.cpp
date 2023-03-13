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
  bool is(TreeNode*lr,TreeNode*rr){
      if(!lr and !rr)return true;
      if(!lr || !rr ||lr->val!=rr->val)return false;
      return is(lr->left,rr->right)&&is(lr->right,rr->left);
  }
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
      return is(root->left,root->right);
        
    }
};