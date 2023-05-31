class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        int n=persons.size();
        vector<pair<int,int>>v;//vector pair to keep track of persons index after sorting
        for(int i=0;i<n;i++)
            v.push_back({persons[i],i});
        sort(v.begin(),v.end());//sorted v based on time
        sort(flowers.begin(),flowers.end());//sorted flowers based on start time
        vector<int>ans(n);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;//min heap
        int index=0;//index to keep track of flowers array
        for(int i=0;i<n;i++)
        {
            //loop to add all flowers whose start time is less than current persons time
            while(index<flowers.size() && flowers[index][0]<=v[i].first)
            {
                pq.push({flowers[index][1],flowers[index][0]});
                index++;
            }
            //loop to remove all flowers whose end time is less than current persons time
            while(!pq.empty() && pq.top().first<v[i].first)
                pq.pop();
            
            ans[v[i].second]=pq.size();
            
        }
        return ans;
    }
};