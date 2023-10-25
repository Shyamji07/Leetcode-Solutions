let depthFirstSearch = (n, k, rootVal) => {
    if (n === 1) {
        return rootVal;
    }

    let totalNodes = Math.pow(2, n - 1);

    // Target node will be present in the right half sub-tree of the current root node.
    if (k > totalNodes / 2) {
        let nextRootVal = (rootVal === 0) ? 1 : 0;
        return depthFirstSearch(n - 1, k - (totalNodes / 2), nextRootVal);
    }
    // Otherwise, the target node is in the left sub-tree of the current root node.
    else {
        let nextRootVal = (rootVal === 0) ? 0 : 1;
        return depthFirstSearch(n - 1, k, nextRootVal);
    }
};

let kthGrammar = function(n, k) {
    return depthFirstSearch(n, k, 0);
};