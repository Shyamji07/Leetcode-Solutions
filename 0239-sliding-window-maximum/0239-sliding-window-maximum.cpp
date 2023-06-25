class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        
     priority_queue<pair<int,int>> pq; // element -> index
    // vec to store the results
    vector<int> res;
    // left and right bound of our window
    int right = 0, left = 0;

    // outer loop
    while(right < arr.size())
    {
        // add every element into the PQ
        pq.push({arr[right] , right});
        // window is not full... expand it
        if(right - left + 1 < k)
            right++;
        // window is full
        else if(right - left + 1 == k)
        {
            // remove the element not in the window from the PQ
            while(pq.top().second < left)
                pq.pop();
            // push the max elemnet from the window into the PQ
            res.push_back(pq.top().first);
            // slide the window
            left++; right++;
        }
    }
    return res;
    }
};

// Complexity:
// The TC should be O(n*logK).

// Max size of heap at any time is K.
// We are inserting every element in the heap once which will cost us O(nlogK)
// The inner loop is used to remove elements from the heap. So it will also run N times in total which will cost us O(nlogK)
// Hence total TC will be 2O(nlogK) == O(n*logk)

// And space complexity will be O(k) for maxheap.



//Using Deque
// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         deque<int> dq;
//         vector<int> ans;
//        for(int i=0;i<nums.size();i++){
//            if(!dq.empty() and dq.front()==i-k)dq.pop_front();
//            while(!dq.empty() and nums[dq.back()]<=nums[i])dq.pop_back();
//            dq.push_back(i);
//            if(i>=k-1)ans.push_back(nums[dq.front()]);
//        }
//         return ans;
//     }
// };