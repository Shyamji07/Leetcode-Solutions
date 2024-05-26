// class Solution {
// public:
//     int mergeSort(vector<long>& sum, int lower, int upper, int low, int high)
//     {
//         if(high-low <= 1) return 0;
//         int mid = (low+high)/2, m = mid, n = mid, count =0;
//         count =mergeSort(sum,lower,upper,low,mid) +mergeSort(sum,lower,upper,mid,high);
//         for(int i = low;i < mid; ++i){
//             auto m = lower_bound(sum.begin()+mid,sum.begin()+high,sum[i] + lower);
//             auto n = upper_bound(sum.begin()+mid,sum.begin()+high,sum[i] + upper);
//             count += n-m;
//         }
//         inplace_merge(sum.begin()+low, sum.begin()+mid, sum.begin()+high);
//         return count;
//     }
//     int countRangeSum(vector<int>& nums, int lower, int upper) {
//         int len = nums.size();
//         vector<long> sum(len + 1, 0);
//         for(int i =0; i< len; i++) sum[i+1] = sum[i]+nums[i];
//         return mergeSort(sum, lower, upper, 0, len+1);
//     }
// };
class Solution {
public:
    int sort_count(vector<long>& sums, int l, int r, int lower, int upper) {
        if (r - l <= 1) return 0;
        int m = (l + r) / 2, i, j1, j2;
        int count = sort_count(sums, l, m, lower, upper) + sort_count(sums, m, r, lower, upper);
        for (i = l, j1 = j2 = m; i < m; ++i) { 
            // we have two j pointers now and one i pointer, but still linear time
            while (j1 < r && sums[j1] - sums[i] < lower) j1++; 
            while (j2 < r && sums[j2] - sums[i] <= upper) j2++;
            count += j2 - j1;
        }
        inplace_merge(sums.begin() + l, sums.begin() + m, sums.begin() + r);
        return count;
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long> sums(n + 1, 0);
        for (int i = 0; i < n; ++i) sums[i + 1] = sums[i] + nums[i];
        return sort_count(sums, 0, n + 1, lower, upper);
    }
    
};