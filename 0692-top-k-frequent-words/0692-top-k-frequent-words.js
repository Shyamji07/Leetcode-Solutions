var topKFrequent = function(words, k) {
    let m = new Map();
    words.forEach(word => m.set(word, m.get(word)+1 || 1));
    let arr = Array.from(m.entries()).sort((a,b) => {
					return a[1] === b[1] ? a[0].localeCompare(b[0]) : b[1]-a[1];
					}).slice(0,k).map(pair => pair[0]);
    return arr;
    // Time Complexity: O(nlog(n))
    // Space Complexity: O(n)
};