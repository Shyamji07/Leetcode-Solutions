var combinationSum3 = function(k, n) {
    const res = []
    
    function permute(arr, sum, start) {
        if(sum > n) return;
        
        if(arr.length === k) {
            if(sum === n) res.push(arr);
            return;
        }
        
        for(let i = start; i < 10; i++) {
            permute([...arr, i], sum+i, i+1);
        }
    }
    permute([], 0, 1);
    return res;
};