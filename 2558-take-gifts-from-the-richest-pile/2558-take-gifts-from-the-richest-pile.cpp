class Solution {
public:
    long long pickGifts(vector<int>& g, int k) {
    make_heap(begin(g), end(g));
    while(k--) {
        pop_heap(begin(g), end(g));
        g.back() = sqrt(g.back());
        push_heap(begin(g), end(g));
    }
    return accumulate(begin(g), end(g), 0LL);
}
};