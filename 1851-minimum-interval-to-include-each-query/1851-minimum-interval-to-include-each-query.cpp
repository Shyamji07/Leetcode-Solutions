class Solution {  // Unordered_Map + Max_Heap
public:
    struct comp{
        bool operator()(pair<int , int>p1, pair<int , int>p2){
            return p1.first  >=  p2.first;
        }
    };
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        // priority_queue<vector<int>> pq;
        priority_queue<pair<int,int> , vector<pair<int,int>>,comp>pq;
        unordered_map<int, int> result;
        vector<int> sortedQueries = queries, result2;
        sort(intervals.begin(), intervals.end());
        sort(sortedQueries.begin(), sortedQueries.end());
        int i = 0, n = intervals.size();
        for (int q : sortedQueries) {
            while (i < n && intervals[i][0] <= q) {
                int start = intervals[i][0], end = intervals[i++][1];
                pq.push({end - start + 1, end});
            }
            while (pq.size() && pq.top().second < q)
                pq.pop();
            result[q] = pq.size() ? pq.top().first : -1;
        }
        for (int q : queries)
            result2.push_back(result[q]);
        return result2;
    }
};
