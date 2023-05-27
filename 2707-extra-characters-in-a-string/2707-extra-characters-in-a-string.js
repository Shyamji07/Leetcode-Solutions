var minExtraChar = function(s, dictionary) {
    const dic = {};
    const memo = new Array(s.length);

    let current;
    for (let i = 0; i < dictionary.length; ++i) {
        current = dic;
        for (let j = 0; j < dictionary[i].length; ++j) {
            if (!current[dictionary[i][j]]) current[dictionary[i][j]] = {};
            current = current[dictionary[i][j]];
        }
        current.end = true;
    }
    
    const check = (index, node) => {
        if (index === s.length) return 0;
        if (memo[index] !== undefined) return memo[index];

        let ret = check(index + 1, dic) + 1;
        let currentNode = node[s[index]];
        let currentIndex = index;
        while (currentNode) {
            currentIndex++;
            if (currentNode.end) ret = Math.min(ret, check(currentIndex, dic));
            currentNode = currentNode[s[currentIndex]];
        }

        return memo[index] = ret;
    };

    return check(0, dic);
};