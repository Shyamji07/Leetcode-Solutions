#define pi pair<int , int> 
class Solution {
public:
    struct comp{
        bool operator()(pi p1 , pi p2){
            return p1.first >= p2.first;
        }
    };
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        priority_queue<pi , vector<pi> , comp>pq;   //{interval length , end_time} sort length come first
        unordered_map<int , int>mp;                 // for storing answer as because original answer is not in sorted order 
        vector<int>Q = queries, res;
        sort(begin(intervals) , end(intervals));
        sort(begin(Q) , end(Q));
        
        int i = 0, n = intervals.size();
        for(int q : Q){
            while(i < n and intervals[i][0] <= q){ // starting point is lesser than q then add into the queue
                int start = intervals[i][0] , end = intervals[i++][1];
                pq.push({end - start + 1 , end});
            }
            while(!pq.empty() and pq.top().second < q) //if end point is also less than q then it mean q is out of the range of interval 
                pq.pop();
            mp[q] = !pq.empty() ? pq.top().first : -1;    // else map querry to length
        }
        for(int q : queries)      // push answer in desired order
            res.push_back(mp[q]);
        return res;
    }
};