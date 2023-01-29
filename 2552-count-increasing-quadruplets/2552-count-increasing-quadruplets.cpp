#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ll long long
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>

class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int n= nums.size();

        ordered_set st2;
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(int j=n-1;j>i;j--)
            {
                if(nums[j]< nums[i])
                {
                   int x= st2.order_of_key(nums[j]);
                   int y= cnt;
                   ans+= x* y;
                }
                else if(nums[j] > nums[i]) cnt++;
            }
            st2.insert(nums[i]);
            
        }
        
        return ans;
        
    }
};