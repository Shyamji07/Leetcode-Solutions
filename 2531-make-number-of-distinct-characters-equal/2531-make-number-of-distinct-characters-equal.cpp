class Solution {
public:
    bool isItPossible(string word1, string word2) {
        vector<int> a(26),b(26);
        for(int q:word1)
            ++a[q-'a'];
        for(int q:word2)
            ++b[q-'a'];
        int n1=0,n2=0;
        for(int q:a)
            n1+=q>0;
        for(int q:b)
            n2+=q>0;
        if(abs(n1-n2)>2)
            return false;
        for(int i=0;i<26;++i)
            for(int j=0;j<26;++j){
                if(a[i]>0&&b[j]>0){
                    --a[i];
                    ++a[j];
                    --b[j];
                    ++b[i];
                    int a1=0,a2=0;
                    for(int q:a)
                        a1+=q>0;
                    for(int q:b)
                        a2+=q>0;
                    if(a1==a2)
                        return true;
                    ++a[i];
                    --a[j];
                    ++b[j];
                    --b[i];
                }
            }
        
        return false;
    }
};