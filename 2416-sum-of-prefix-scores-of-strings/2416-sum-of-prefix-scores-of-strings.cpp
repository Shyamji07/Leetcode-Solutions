class Solution {
public:
    struct TrieNode{
        TrieNode *children[26]={NULL};
        int count=0;
    };
    TrieNode *root=new TrieNode();
    void insert(string word){
        int n = word.size();
        TrieNode *temp = root;
        for(int i=0; i<n; i++){
            int x = (int)(word[i] - 'a');
            if(!temp->children[x])
                temp->children[x] = new TrieNode();
            temp = temp->children[x];
            temp->count++;
        }
    }
    vector<int> sumPrefixScores(vector<string>& s) {
       vector<int>ans(s.size());
        for(auto a:s)insert(a);
        for(int i=0;i<s.size();i++){
            int len=0;
            int n=s[i].size();
            TrieNode *temp = root;
            for(int j=0; j<n; j++){
              int x = (int)(s[i][j] - 'a');
              if(!temp->children[x])break;
              temp = temp->children[x];
              len+=temp->count;
            }
            ans[i]=len;
        }
        return ans;
    }
};