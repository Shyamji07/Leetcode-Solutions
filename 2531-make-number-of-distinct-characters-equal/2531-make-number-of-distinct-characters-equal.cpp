class Solution {
public:
    bool isItPossible(string word1, string word2) {
    int cnt1[26] = {}, cnt2[26] = {}, dist1 = 0, dist2 = 0;
    for (auto ch : word1)
        dist1 += ++cnt1[ch - 'a'] == 1;
    for (auto ch : word2)
        dist2 += ++cnt2[ch - 'a'] == 1;
    if (dist1 == dist2 && inner_product(begin(cnt1), end(cnt1), begin(cnt2), 0LL, plus<>(), multiplies<long long>()))
        return true;
    for (int i = 0; i < 26; ++i)
        if (cnt1[i])
            for (int j = 0; j < 26; ++j)
                if (cnt2[j])
                    if (i != j && dist1 - (cnt1[i] == 1) + (cnt1[j] == 0) ==
                       dist2 - (cnt2[j] == 1) + (cnt2[i] == 0))
                        return true;
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

