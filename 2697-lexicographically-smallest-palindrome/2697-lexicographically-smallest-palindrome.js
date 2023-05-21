/**
 * @param {string} s
 * @return {string}
 */
var makeSmallestPalindrome = function(s) {
    let n = s.length;

    let ml = Math.floor(n / 2) - 1;
    let mr = ml + 1;
    if (n % 2 == 1) ml++;

    let ans = "";
    for(let l = ml, r = mr; l >= 0, r < n; l--, r++) {
        if (s[l] != s[r]) {
            if (s.charCodeAt(l) < s.charCodeAt(r)) {
                ans = s[l] + ans + s[l];
            } else {
                ans = s[r] + ans + s[r];
            }
        } else {
            if (l == r) {
                ans = ans + s[l];
            } else {
                ans = s[l] + ans + s[l];
            }                        
        }
    }

    return ans;
};