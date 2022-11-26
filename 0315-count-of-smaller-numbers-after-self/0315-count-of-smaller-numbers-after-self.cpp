#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
class Solution {
public:
    vector<int> countSmaller(vector<int>& arr) {
        const int N = arr.size();
        vector<int> v(N,0);
        ordered_set s;
        v[N-1]=0;
        s.insert(arr[N-1]);
        for(int i=N-2;i>=0;i--){
           //if arr[i] not in the set but it will show the
          // index number if it was there in sorted array.
            int it = s.order_of_key(arr[i]); //index of number arr[i] in sorted array.
            v[i]=it;
            s.insert(arr[i]);
        }
        return v;
    }
};