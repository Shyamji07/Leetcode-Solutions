var convert = function(s, numRows) {
    const n = s.length
    if(numRows == 1){
        return s
    }
    const res = new Array(numRows).fill("")
    let up = false
    let k = 1
    for(let i=0; i<n; i++){
        res[k-1] += s[i]
        if(k === numRows){
            up = true
        } else if(k === 1){
            up = false
        }
        
        k = up ? k-1 : k+1
    }
    return res.join("")
};