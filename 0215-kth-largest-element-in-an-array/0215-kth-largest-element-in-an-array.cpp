class Solution {
public: // T.C -->O(N)+O(KlogN)===>O(NlogN) S.C ==>O(N)
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(),nums.end()); //T.C ->O(N)
        while(--k>0){   //T.C--> O(KlogN);
            pq.pop();
        }
        return pq.top();
    }
};