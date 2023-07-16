class Solution {
public:
      bool is_letter(char c)
    {
        return (c>='a' && c<='z') || (c>='A' && c<='Z');
    }
    bool is_lower(char c)
    {
        return c>='a' && c<='z';
    }
    vector<string> letterCasePermutation(string S) {
        vector<string> ret;
        ret.push_back(S);
        for(size_t i = 0;i<S.size();i++)
        {
            if(is_letter(S[i]))
            {
                char alternative = is_lower(S[i]) ? S[i] - 32 : S[i]+32;
                size_t n = ret.size();
                for(size_t j = 0;j<n;j++)
                {
                    string permu = ret[j];
                    permu[i] = alternative;
                    ret.push_back(permu);
                }
            }
        }
        return ret;
    }
};