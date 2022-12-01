var lowestCommonAncestor = (root, p, q)=> {
    if(!root || root===p || root===q)return root;
    let left=(lowestCommonAncestor(root.left,p,q));
    let right=(lowestCommonAncestor(root.right,p,q));
    return !left ? right : (!right ? left : root);
};