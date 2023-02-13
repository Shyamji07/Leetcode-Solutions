/**
 * @param {number} low
 * @param {number} high
 * @return {number}
 */
var countOdds = function(low, high) {
    return Math.floor((high - low) / 2) + ((low | high) & 1);
};