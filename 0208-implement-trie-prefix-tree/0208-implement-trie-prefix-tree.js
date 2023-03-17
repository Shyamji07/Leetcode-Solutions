var Trie = function() {
    this.words = [];
};

Trie.prototype.insert = function(word) {
    this.words.push(word)
};

Trie.prototype.search = function(word) {
    return this.words.includes(word)
};


Trie.prototype.startsWith = function(prefix) {
     return this.words.find(element => element.startsWith(prefix)) !== undefined
};