class Solution {
public:
    void recursion(vector<int> num, int i, int j, vector<vector<int> > &res) {
        if (i == j-1) {
            res.push_back(num);
            return;
        }
        for (int k = i; k < j; k++) {
            swap(num[i], num[k]);
            recursion(num, i+1, j, res);
            swap(num[i], num[k]);
        }
    }
    vector<vector<int>> permute(vector<int>& num) {
        vector<vector<int> >res;
        recursion(num, 0, num.size(), res);
        return res;
    }
};
