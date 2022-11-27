/**
 * @param {number} n
 * @return {number}
 */
var pivotInteger = function(n) {
    
    for (let i = 1; i <= n; i++) {
        const leftSum = Math.floor((i * (i + 1)) / 2);
        const rightSum = Math.floor((n * (n + 1)) / 2) - Math.floor(((i - 1) * i) / 2);
        if (leftSum === rightSum) {
            return i;
        }
    }
    
    return -1;
};