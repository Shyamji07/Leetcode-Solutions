class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int> >heap;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            heap.push({abs(x-arr[i]),arr[i]});
            if(heap.size()>k)
            {
                heap.pop();
            }
        }
        vector<int> sol;
        while(heap.size()>0)
        {
            sol.push_back(heap.top().second);
            heap.pop();
        }
        sort(sol.begin(),sol.end());
        return sol;
    }
};