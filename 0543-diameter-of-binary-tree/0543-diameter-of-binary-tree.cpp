// class Solution {
// public:
//  int dfs(TreeNode* root) {
//         if (!root) return 0;
//         int left = (root->left and mp[root->left])?mp[root->left]:dfs(root->left);
//         int right = (root->right and mp[root->right])?mp[root->right]:dfs(root->right);                                              
//         diameter = max(diameter, left + right);
//         return mp[root]=max(left, right) + 1;
//     }
    
//     int diameterOfBinaryTree(TreeNode* root) {
//         dfs(root);
//         return diameter;
//     }
    
// private:
//        unordered_map<TreeNode*,int>mp;
//        int diameter = 0;
// };

class Solution {  // Upper code has fast runtime
public:
 int dfs(TreeNode* root) {
        if (!root) return 0;
        int left = dfs(root->left), right = dfs(root->right);
        diameter = max(diameter, left + right);
        return max(left, right) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return diameter;
    }
    
private:
    int diameter = 0;
};