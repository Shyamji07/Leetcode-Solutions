class Solution {  // Unordered_Map + Max_Heap
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        priority_queue<vector<int>> pq;
        unordered_map<int, int> result;
        vector<int> sortedQueries = queries, result2;
        sort(intervals.begin(), intervals.end());
        sort(sortedQueries.begin(), sortedQueries.end());
        int i = 0, n = intervals.size();
        for (int q : sortedQueries) {
            while (i < n && intervals[i][0] <= q) {
                int start = intervals[i][0], end = intervals[i++][1];
                pq.push({start - end - 1, end});
            }
            while (pq.size() && pq.top()[1] < q)
                pq.pop();
            result[q] = pq.size() ? -pq.top()[0] : -1;
        }
        for (int q : queries)
            result2.push_back(result[q]);
        return result2;
    }
};
