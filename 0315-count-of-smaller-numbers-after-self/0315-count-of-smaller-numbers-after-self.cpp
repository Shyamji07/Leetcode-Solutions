/* Using Segment Tree */
class Solution { 
public:
    struct SegmentTree{
        vector<int> tree;
        int n;
        SegmentTree(int n){
            this->n = n;
            tree.resize(4*(n+4));
        }
        
        int left(int node){return 2*node+1;}
        int right(int node) {return 2*node+2;}
        
        void update(int node, int s, int e, int val){
            if(s>e) return;
            if(s==e){
                tree[node]++;
                return;
            }
            
            int mid = s + (e-s)/2;
            if(val<=mid) update(left(node), s, mid, val);
            else update(right(node), mid+1, e, val);
            tree[node] = tree[left(node)] + tree[right(node)];
        }
        
        int query(int node, int s, int e, int qs, int qe){
            if(s>e || qe < s || qs > e) return 0;
            if(s>=qs && e<=qe) return tree[node];
            
            int mid = s + (e-s)/2;
            int l = query(left(node),s,mid,qs,qe);
            int r = query(right(node),mid+1,e,qs,qe);
            return l+r;
        }
        
    };
    
    void convert(vector<int>& nums){
        int sz = nums.size();
        for(int i=0; i<sz; ++i) nums[i]+=10000;
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        convert(nums); // coverting range(-10000,10000) to range(0,20000);
        int maxE = *max_element(nums.begin(), nums.end());
        SegmentTree *st = new SegmentTree(maxE+1);
        
        int sz = nums.size();
        vector<int> ans(sz,0);
        for(int i=sz-1; i>=0; --i){
            st->update(0,0,maxE,nums[i]);
            int l =0, r = nums[i]-1;
            ans[i] = st->query(0,0,maxE,0,r);
        }
        return ans;
    }
};








/* Using Ordered_Set */
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
// #include <ext/pb_ds/detail/standard_policies.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// class Solution {
// public:
//     vector<int> countSmaller(vector<int>& arr) {
//         const int N = arr.size();
//         vector<int> v(N,0);
//         ordered_set s;
//         v[N-1]=0;
//         s.insert(arr[N-1]);
//         for(int i=N-2;i>=0;i--){
//            //if arr[i] not in the set but it will show the
//           // index number if it was there in sorted array.
//             int it = s.order_of_key(arr[i]); //index of number arr[i] in sorted array.
//             v[i]=it;
//             s.insert(arr[i]);
//         }
//         return v;
//     }
// };








/* Using Merge Sort */

// class Solution {  //t.c  O(NlogN)  s.c O(N)
// public:
// 	vector<int> ans;
// 	vector<pair<int,int>> nums;

// 	void getRevInv(int i1,int j1,int i2,int j2) {
// 		int i=i1,c=0;
// 		vector<pair<int,int>> v;
// 		while(i1<=j1 && i2<=j2) {
// 			if(nums[i2].first>=nums[i1].first) v.push_back(nums[i2++]);
// 			else {
// 				v.push_back(nums[i1]);
// 				ans[nums[i1++].second]+= j2-i2+1;
// 			}
// 		}
// 		while(i1<=j1) v.push_back(nums[i1++]); // i2 reach at end
// 		while(i2<=j2) v.push_back(nums[i2++]);// i1 at end
// 		for(auto j: v) nums[i++]=j;  //copying from temp array to original array after sorting of individual part
// 	}

// 	void merge(int i,int j) {
// 		if(i==j) return;
// 		int mid= (i+j)/2;
// 		merge(i,mid);
// 		merge(mid+1,j);
// 		getRevInv(i,mid,mid+1,j);
// 	}

// 	vector<int> countSmaller(vector<int>& arr) {
// 		int n= arr.size();
// 		ans.clear(); ans.resize(n,0);
// 		nums.clear();
// 		for(int i=0;i<n;i++) nums.push_back({arr[i],i});
// 		merge(0,n-1);
// 		return ans;
// 	}
// };


/* Using Merge Sort with the help of iterator and inplace_merge builtin function */
    
//      #define iterator vector<vector<int>>::iterator
//     void sort_count(iterator l, iterator r, vector<int>& count) {
//         if (r - l <= 1) return;
//         iterator m = l + (r - l) / 2;
//         sort_count(l, m, count);
//         sort_count(m, r, count);
//         for (iterator i = l, j = m; i < m; i++) {
//             while (j < r && (*i)[0] > (*j)[0]) j++;
//             count[(*i)[1]] += j - m; // add the number of valid "j"s to the indices of *i
//         }
//         inplace_merge(l, m, r);
//     }
//     vector<int> countSmaller(vector<int>& nums) {
//         vector<vector<int>> hold;
//         int n = nums.size();
//         for (int i = 0; i < n; ++i) hold.push_back(vector<int>({nums[i], i})); // "zip" the nums with their indices
//         vector<int> count(n, 0);
//         sort_count(hold.begin(), hold.end(), count);
//         return count;
//     }
// };








/*Main Template of these type of question

   // [l, r) is the interval to be sorted
    int sort_count(iterator l, iterator r) {
        if (r - l <= 1) return; 
        // step 1. find the middle
        iterator m = l + (r - l) / 2;
        // step 2. sort left and right subarray
        int count = sort_count(l, m) + sort_count(m, r);
        */
        /* step 3. write your code here for counting the pairs (i, j).*/
				
        // step 4. call inplace_merge to merge
    //     inplace_merge(l, m, r);
    //     return count;
    // }