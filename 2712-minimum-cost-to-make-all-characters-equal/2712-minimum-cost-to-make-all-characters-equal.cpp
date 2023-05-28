/**
 * @param {string} s
 * @return {number}
 */
var minimumCost = function(s) {
    let a = 0;
    for (let i = 1; i < s.length; i++) {
        a += s[i - 1] === s[i] ? 0 : Math.min(i, s.length - i);
    }
    return a;

};