/**
 * @param {string} sentence
 * @return {boolean}
 */
var isCircularSentence = function(s) {
    for (let i = 0; i < s.length; ++i)
            if (s[i] == ' ' && s[i-1] != s[i+1])
                return false;
        return s[0] == s[s.length-1];
};