class Solution {
    public:
        bool isItPossible(string s1, string s2) {
            vector<int> a(26,0),b(26,0);
            for(int i=0;i<s1.size();i++){
                a[s1[i]-'a']++;
            }
            for(int i=0;i<s2.size();i++){
                b[s2[i]-'a']++;
            }
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(a[i]>0 && b[j]>0){
                    a[i]--;  b[j]--;
                    b[i]++;  a[j]++;
                    int counta=0,countb=0;
                    for(int l=0;l<26;l++){
                        if(a[l]>=1)counta++;
                        if(b[l]>=1)countb++;
                    }
                    if(counta==countb)return true;
                    a[i]++;b[j]++;
                    b[i]--;  a[j]--;
                    }
                }
            }
            return false;
        }
    };

static int fastio = []() {
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();

