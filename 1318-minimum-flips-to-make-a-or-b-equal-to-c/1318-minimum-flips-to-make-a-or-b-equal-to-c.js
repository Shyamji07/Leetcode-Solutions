var minFlips = function(a, b, c) {
    let minFlip = 0

    while(a || b || c){
        const bitA = a & 1
        const bitB = b & 1
        const bitC = c & 1
        if ((bitA || bitB) !== bitC){
            bitC === 1 ? minFlip += 1 : minFlip += (bitA === 1) + (bitB === 1)
        }
        a >>= 1
        b >>= 1
        c >>= 1
    }
    return minFlip
};