/**
 * @param {string} num
 * @return {string}
 */
var removeTrailingZeros = function(num) {
    while (num[num.length - 1] === '0') {
            num = num.slice(0, -1);
        }
    return num;
};