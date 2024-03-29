class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int count = 0;
        vector<int> expected = heights;
        sort(heights.begin(), heights.end());
        for(int i = 0; i < expected.size(); i++)
            if(expected[i] != heights[i]) count++;

        return count;
    }
};