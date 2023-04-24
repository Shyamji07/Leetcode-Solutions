class Solution {
public:
    int lastStoneWeight(vector<int>& s) {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            cout.tie(NULL);
            int n=s.size();
            priority_queue<int>pq;
            for(int i=0;i<n;i++){
                    pq.push(s[i]);
            }
            while(pq.size()>1){
                    int t1=pq.top();
                    pq.pop();
                    int t2=pq.top();
                    pq.pop();
                    if(t1!=t2)pq.push(abs(t1-t2));
            }
        return pq.size()==1?pq.top():0;
    }
};