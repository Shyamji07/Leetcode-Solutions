class KthLargest {
private:
    priority_queue <int, vector<int>, greater<int>> pq_elems;
    int num_elems;
public:
    KthLargest(int k, vector<int>& nums) {
        num_elems = k;
      
        for(int i=0; i<nums.size(); i++)
        {
            pq_elems.push(nums[i]);
            if(pq_elems.size()>k)
                pq_elems.pop();
            
        }
    }
    
    int add(int val) {
        if(pq_elems.size() < num_elems)
            pq_elems.push(val);
         else
         {
             if(val > pq_elems.top())
            {
                pq_elems.pop();
                pq_elems.push(val);
            }
         }
        return pq_elems.top();
        
    }
};
