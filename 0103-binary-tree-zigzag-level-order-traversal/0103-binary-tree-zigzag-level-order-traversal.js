var zigzagLevelOrder = function(root) {
     if(!root) return [];
    let queue = [root];
    let levels = [];
    while(queue.length > 0) {
        let levelSize = queue.length;
        levels.push([]);
        for(let i = 0; i < levelSize; i++) {
            let curr = queue.shift();
            if(levels.length % 2 == 1) levels[levels.length - 1].push(curr.val);
            else levels[levels.length - 1].unshift(curr.val);  
            
            if(curr.left) queue.push(curr.left);
            if(curr.right) queue.push(curr.right);
        }
    }
    
    return levels;
};