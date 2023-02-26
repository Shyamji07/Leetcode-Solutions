var levelOrder = function(root) {
     let q = [root], ans = []
    while (q[0]) {
        let qlen = q.length, row = []
        for (let i = 0; i < qlen; i++) {
            let curr = q.splice(0,1)
            row.push(curr[0].val)
            if (curr[0].left) q.push(curr[0].left)
            if (curr[0].right) q.push(curr[0].right)
        }
        ans.push(row)            
    }
    return ans
};