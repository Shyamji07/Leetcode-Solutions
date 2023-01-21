class Solution {
public:
    bool is(string s){
        int n=s.size();
        if(n==1)return true;
        if(n>3||s[0]=='0')
            return false;
        int temp=stoi(s);
        if(temp>255)
            return false;

        return true;
    }
    vector<string> restoreIpAddresses(string s) {
        int n=s.size();
        vector<string>res;
        string a,b,c,d;
        if(n>12){
            return res;
        }

        for(int i=1;i<=3;i++){
            for(int j=1;j<=3;j++){
                for(int k=1;k<=3;k++){
                    if(i+j+k<n and i+j+k+3>=n){
                         a=s.substr(0,i);
                         b=s.substr(i,j);
                         c=s.substr(j+i,k);
                         d=s.substr(i+j+k);
                        if(is(a)&&is(b)&&is(c)&&is(d)){
                            res.push_back(a+"."+b+"."+c+"."+d);
                        }
                    }
                }
            }
        }
        return res;
    }
};