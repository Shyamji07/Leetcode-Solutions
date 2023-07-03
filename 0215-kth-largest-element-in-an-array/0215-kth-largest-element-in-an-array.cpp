class Solution {  //T.C ==> O(n.logK)
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> heap;
        for (int num: nums) {
            heap.push(-num);
            if (heap.size() > k) {
                heap.pop();
            }
        }
        
        return -heap.top();
    }
};

// class Solution {
// public: // T.C -->O(N)+O(KlogN)===>O(NlogN) S.C ==>O(N)
//     int findKthLargest(vector<int>& nums, int k) {
//         priority_queue<int> pq(nums.begin(),nums.end()); //T.C ->O(N)
//         while(--k>0){   //T.C--> O(KlogN);
//             pq.pop();
//         }
//         return pq.top();
//     }
// };

// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         partial_sort(nums.begin(), nums.begin() + k, nums.end(), greater<int>());
//         return nums[k - 1];
//     }
// };

// //MERGESORT ALGORITHM

// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         nth_element(nums.begin(),nums.begin()+k-1,nums.end(),std::greater<int>());
//         return nums[k-1];
//     }
// };