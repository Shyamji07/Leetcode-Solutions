class Solution {
public:
    unordered_map<int, int> mp;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < size(inorder); i++) mp[inorder[i]] = i;
        int n = size(inorder), postIdx = n-1;
        return build(inorder, postorder, 0, n-1, postIdx);
    }

    TreeNode* build(vector<int>& in, vector<int>& post, int inStart, int inEnd, int& postIdx) {
        if(inStart > inEnd) return nullptr;
        TreeNode* root = new TreeNode(post[postIdx--]);
        int inIdx = mp[root -> val];
        root -> right = build(in, post, inIdx+1, inEnd, postIdx);
        root -> left  = build(in, post, inStart, inIdx-1, postIdx);
        return root;
    }
};