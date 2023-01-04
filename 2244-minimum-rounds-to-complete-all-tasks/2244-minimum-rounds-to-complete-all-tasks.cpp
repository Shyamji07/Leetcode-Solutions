class Solution {
public:
    int minimumRounds(vector<int>& v) {
        map<int,int>m;
        int count=0;
        int n=0;
        for(int i=0;i<v.size();i++){
            m[v[i]]++;
        }
        for(auto val:m){
            if(val.second==1)return -1;
            else count+=((val.second+2)/3);
        }
        
        return count;
    }
};