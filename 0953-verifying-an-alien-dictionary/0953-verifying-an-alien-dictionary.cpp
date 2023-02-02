class Solution {
public:
    bool isAlienSorted(const vector<string>& words, const string& order) {
        array<int, 26> ord {};
        for(int i = 0; i < order.size(); ++i) {
            ord[order[i] - 'a'] = i;
        }
        
        auto comp = [&ord] (char a, char b) {
            return ord[a - 'a'] < ord[b - 'a'];  
        };
        
        for(int i = 1; i < words.size(); ++i) {
            const auto& prev = words[i-1];
            const auto& curr = words[i];
            if (lexicographical_compare(curr.begin(), curr.end(), prev.begin(), prev.end(), comp)) {
                return false;
            }
        }
        
        return true;
    }
};