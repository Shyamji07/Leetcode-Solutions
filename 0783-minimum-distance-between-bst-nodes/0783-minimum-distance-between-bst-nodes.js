var minDiffInBST = function(root) {
    let min = Infinity, prev;
    const traversal = (root) => {
        if (root == null) return;
        traversal(root.left);
        if (prev != null) min = Math.min(min, root.val - prev.val);
        prev = root;
        traversal(root.right);
    }

    traversal(root);
    return min;    
};