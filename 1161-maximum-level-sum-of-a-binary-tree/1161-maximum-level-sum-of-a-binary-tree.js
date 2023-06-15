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
 * @return {number}
 */
var maxLevelSum = function(root) {
    if(root == null) return 0;
     let maxsum=root.val;
        let lev=0;
        let ans=1;
        const q=[root];
        while(q.length){
            let n=q.length;
            lev++;
            let sumlev=0;
            while(n--){
                let temp=q.shift();
                sumlev+=temp.val;
                if(temp.left){
                q.push(temp.left);
                }
                if(temp.right){
                q.push(temp.right);
                }
            }
            if(sumlev>maxsum){
                maxsum=sumlev;
                ans=lev;
            }
        }
        return ans;
};
// var maxLevelSum = function(root) {
//     if(root == null) return 0;
//     let node = root;
//     let level = 0;
//     let q = [node];
//     let maxSumLevel = 1;
//     let sum = root.val;
//     while(q.length){
//         let insideSum=0;
//         let len = q.length;
//         level++;
//         for(let i =0;i<len; i++){
//             let node = q.shift();
//             insideSum += node.val;
//             node.left && q.push(node.left);
//             node.right && q.push(node.right);
//         }
//         if(insideSum>sum) {
//             sum = insideSum;
//             maxSumLevel = level;
//         };
//     }
//     return maxSumLevel;
// };