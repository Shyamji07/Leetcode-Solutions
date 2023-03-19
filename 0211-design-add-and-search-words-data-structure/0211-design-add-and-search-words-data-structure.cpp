class TrieNode {
public:
    bool word=false;
    TrieNode* children[26]={NULL};
};
class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node -> children[c - 'a']) {
                node -> children[c - 'a'] = new TrieNode();
            }
            node = node -> children[c - 'a'];
        }
        node -> word = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
         ios_base::sync_with_stdio(NULL);
         cin.tie(0);
        return search(word, root);
    }
private:
   
    TrieNode* root = new TrieNode();
    
    bool search(string word, TrieNode* node) {
        for (int i = 0; word[i] && node; i++) {
            if (word[i] != '.') {
                node = node -> children[word[i] - 'a'];
            } else {
                TrieNode* tmp = node;
                for (int j = 0; j < 26; j++) {
                    node = tmp -> children[j];
                    if (search(word.substr(i+1), node)) {
                        return true;
                    }
                }
            }
        }
        return node && node -> word;
    }
};