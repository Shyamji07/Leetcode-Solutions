class Solution {
public:
    int compress(vector<char>& chars) 
    {
        int count = 0;
        int repeat = 1;
        for(int i=0; i<chars.size(); i++)
        {
            if (i<chars.size()-1 && chars[i] == chars[i+1])
                repeat++;
            else
            {
                chars[count++] = chars[i];
                if (repeat != 1)
                {
                    int j = count;
                    while (repeat > 0)
                    {
                        chars[count++] = repeat%10 +'0';
                        repeat /= 10;
                    }
                    if (count-j>1)
                        reverse(chars.begin()+j,chars.begin()+count);
                    repeat = 1;
                }
            }
        }
        return count;        
    }
};