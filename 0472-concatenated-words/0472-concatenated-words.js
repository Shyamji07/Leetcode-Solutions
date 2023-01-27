// Copied From Discussion (Trie in Javascript)
var findAllConcatenatedWordsInADict = function(words) {
    let root = new Trie("*");

    for (let word of words) {
        buildDict(root, word);
    }

    return words.filter(word => isPresentInDict(root, word, 0, {}) > 2)
};


function isPresentInDict(root, s, start = 0, seen = {}) {
    if (start == s.length) return 1;

    if (seen.hasOwnProperty(start)) {
        return seen[start];
    }

    for (let prefix of root.getMatchingPrefixes(s, start)) {
        let isMatch = isPresentInDict(root, s, prefix + 1, seen);
        if (isMatch > 0) return seen[start] = 1 + isMatch;
    }
    return seen[start] = 0;
}


function Trie(_dir) {
  this.n = {};
  this.isWord = false;
  return this;
}

Trie.prototype.getMatchingPrefixes = function (word, start) {
  let curr = this;
  const prefixes = [];
  for (let i = start; i < word.length; i++) {
    let char = word[i];
      if (!curr.n[char]) {
        return prefixes;
      }
      if (curr.n[char].isWord) {
          prefixes.push(i);
      }
      curr = curr.n[char];
  }
  return prefixes;
}

function buildDict(root, word) {
  let curr = root;
  for (let i = 0; i < word.length; i++) {
    if (!curr.n[word[i]]) {
        curr.n[word[i]] = new Trie(word[i]);
    }
    curr = curr.n[word[i]];
  }
  curr.isWord = true;
}