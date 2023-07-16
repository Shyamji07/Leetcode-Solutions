class Solution {
public:
    vector<string>res;
   void dfs(string digits,string s,int i,map<char,vector<char>>&m){
        if(digits.size()==i){
            res.push_back(s);
            return;
        }
        for(auto a:m[digits[i]]){
            s+=a;
            dfs(digits,s,i+1,m);
            s.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        string s;
        if (digits.size()==0)return {};
        map<char,vector<char>>m;
         m['2'] = {'a','b','c'};
        m['3'] = {'d','e','f'};
        m['4'] = {'g','h','i'};
        m['5'] = {'j','k','l'};
        m['6'] = {'m','n','o'};
        m['7'] = {'p','q','r','s'};
        m['8'] = {'t','u','v'};
        m['9'] = {'w','x','y','z'};   
        
        dfs(digits,s,0,m);
        
        return res;
    }
};