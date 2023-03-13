/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */


var isSymmetric = function(root) {
    if(!root)return true;
     var is=( lr, rr)=>{
      if(!lr && !rr)return true;
      if(!lr || !rr ||lr.val!=rr.val)return false;
      return is(lr.left,rr.right)&&is(lr.right,rr.left);
  }
      return is(root.left,root.right);
};