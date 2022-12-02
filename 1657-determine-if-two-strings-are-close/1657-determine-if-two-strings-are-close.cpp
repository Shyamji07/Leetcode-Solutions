class Solution {
    public:
        bool closeStrings(string s1, string s2) {
            vector<int> map1(26, 0);
            vector<int> map2(26, 0);
            if (size(s1) != size(s2))
                return false;
            for (int i = 0; i < size(s1); i++){
                map1[s1[i] - 'a']++;
                map2[s2[i] - 'a']++;
            }
            for (int i = 0; i < 26; i++)
                if ((map1[i] != 0 && map2[i] == 0) || (map1[i] == 0 && map2[i] != 0))
                    return false;
            sort(map1.begin(),map1.end());
            sort(map2.begin(),map2.end());
           return  map1==map2;
        }
    };