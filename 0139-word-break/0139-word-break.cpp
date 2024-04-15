struct TrieNode{
	TrieNode *children[26]={NULL};
	bool isEnd=false;
};
TrieNode *root;
vector<bool> dp;

void insert(string word)
{
	int n = word.size();
	TrieNode *temp = root;
	for(int i=0; i<n; i++)
	{
		int x = (int)(word[i] - 'a');
		if(!temp->children[x])
			temp->children[x] = new TrieNode();
		temp = temp->children[x];
	}
	temp->isEnd = true;
}

void search(string word, int start)
{
	int n = word.size();
	TrieNode *temp = root;
	for(int i=start; i<n; i++)
	{
		int x = word[i] - 'a';
		if(!temp->children[x])
			return;
		temp = temp->children[x];
		if(temp->isEnd)
			dp[i+1] = 1;
	}

	if(temp->isEnd)
		dp[n] = 1;
}

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		root = new TrieNode();
		int n = size(wordDict), l = s.size();
		dp.assign(l+1, 0);
		for(int i=0; i<n; i++)
			insert(wordDict[i]);

		dp[0] = 1;
		for(int i=0; i<l; i++)
			if(dp[i])
				search(s, i);

		return dp[l];
	}
};