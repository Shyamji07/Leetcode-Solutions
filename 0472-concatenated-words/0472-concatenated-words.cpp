class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& arr) {
        unordered_set<string>st(arr.begin(),arr.end());
        vector<string>ans;
        for(auto w:arr){
            st.erase(w);
            vector<bool>dp(w.size()+1,false);
            dp[0]=true;
            for(int i=1;i<w.size()+1;i++){
                for(int j=0;j<i;j++){
                    string temp=w.substr(j,i-j);
                    if(dp[j] and (st.find(temp)!=st.end())){
                        dp[i]=true;
                        break;
                    }
                }
                if(dp.back())ans.push_back(w);
            }
            st.insert(w);
        }
        return ans;
    }
};


// class Solution {
// public:
//     vector<string> findAllConcatenatedWordsInADict(vector<string>& arr) {
//         int n = arr.size();
//         vector<unordered_set<string> > mp;
//         for(auto &it: arr) {
//             int m = it.size();
//             if(m >= mp.size())
//                 mp.resize(m + 1);
//             mp[m].insert(it);
//         }
//         vector<string> ans;
//         for(auto &m: mp)
//             for(auto &t: m) {
//                 int m = t.size(), msk = 1;
//                 if(!m)
//                     continue;
//                 for(int i = 0; i < m; ++i) {
//                     if(!((msk >> i) & 1))
//                         continue;
//                     string cur = "";
//                     for(int j = i; j < m - !i; ++j) {
//                         cur.push_back(t[j]);
//                         if(mp[j - i + 1].count(cur))
//                             msk |= 1 << (j + 1);
//                     }
//                 }
//                 if((msk >> m) & 1)
//                     ans.push_back(t);
//             }
//         return ans;
//     }
// };