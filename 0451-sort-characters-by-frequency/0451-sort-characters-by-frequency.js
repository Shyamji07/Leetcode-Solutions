var frequencySort = function(s) {
    const counts = new Map();
    for (let c of s) counts.set(c, (counts.get(c) || 0) + 1);
    return s.split('').sort((a, b) => counts.get(b) - counts.get(a) === 0 ? b.localeCompare(a) :  counts.get(b) - counts.get(a)).join('')
};