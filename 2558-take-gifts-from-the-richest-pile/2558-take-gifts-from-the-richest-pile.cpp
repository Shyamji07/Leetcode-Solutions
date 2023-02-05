class Solution {
public:
    long long pickGifts(vector<int>& arr, int k) {
        priority_queue<long long> pq;
        long long ans=0;
        for(auto a: arr)pq.push(a);
        
        while(k--){
            pq.push(sqrt(pq.top()));
            pq.pop();  
        }
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};