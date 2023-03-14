var sumNumbers = function(root) {
    let ans=0;
    let sum =0;
    let solve =(root, ans) => {
    if(!root)return 0;
    ans=ans*10 + root.val;
    if(!root.left&&!root.right)sum+=ans;
    let left=solve(root.left,ans);
    let right=solve(root.right,ans);

    return ans;
}
    solve(root,ans);
    return sum;
};