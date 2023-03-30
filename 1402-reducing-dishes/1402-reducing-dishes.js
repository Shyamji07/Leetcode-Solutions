/**
 * @param {number[]} satisfaction
 * @return {number}
 */
var maxSatisfaction = function(satisfaction) {
        satisfaction.sort((a,b) => b-a)
        let n = satisfaction.length;
        let presum = 0, res = 0;
        for (let i = 0; i < n; i++) {
            presum += satisfaction[i];
            if (presum < 0) {
                break;
            }
            res += presum;
        }
        return res;
};