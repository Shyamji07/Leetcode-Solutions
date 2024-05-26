class Solution { // checking
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
         queue<string> q;
        unordered_set<string> s;
        for(string i:wordList)
            s.insert(i);
        if(s.find(endWord)==s.end())        //check whether the endWord is present in the vector or not
            return 0;
        q.push(beginWord);
        int depth=0;
        while(!q.empty())
        {   depth++;
            int n=q.size();
            while(n--)
            {
                string curr=q.front();
                q.pop();
                for(int i=0;i<curr.length();i++)
                {
                    string temp=curr;                   
                    for(int j=0;j<26;j++)                                  
                    {
                        curr[i]='a'+j;           //try changing each string(in queue) with every alphabet
                        if(curr==temp)
                            continue;
                        if(endWord==curr)
                            return depth+1;
                        if(s.find(curr)!=s.end())
                        {
                            q.push(curr);
                            s.erase(curr);
                        }
                    }
                    curr=temp;
                }
            }
        }
        return 0;
    }
};