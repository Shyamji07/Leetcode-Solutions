class Solution {
public:
    struct comp{    //Comparator function for sorting 
        bool operator()(string s1,string s2){
            return s1.size()<s2.size();
        }
    };
    int longestStrChain(vector<string>& arr) {
        sort(begin(arr),end(arr),comp());// Sort asc according to length
        unordered_map<string,int>mp; //to  store ans for every word 
        int ans=1;
        for(auto s:arr){//check for every word in arr
            mp[s]=1; // string chain must have atleast one word.
            for(int i=0;i<s.size();i++){
                string temp=s.substr(0,i)+s.substr(i+1); //remove charcter one by one and check if new string (string after removing ith character) is present in map then update value in map and our answer as well.
                if(mp.find(temp)!=mp.end()){
                    mp[s]=max(mp[s],mp[temp]+1);
                    ans=max(ans,mp[s]); //update ans if we get more word in chain.
                }
            }
        }
        return ans;  //final
    }
};

// T.C----> O(NlogN)+O(N*max_len_word)
// S.C---->O(N)    