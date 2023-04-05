/**
 * @param {number[]} nums
 * @return {number}
 */
var minimizeArrayValue = function(A) {
    let sum = 0, res = 0;
        for (let i = 0; i < A.length; ++i) {
            sum += A[i];
            res = Math.max(res, Math.floor((sum + i) / (i + 1)));
        }
        return res;
};