#define vi vector<int>
class NumArray {
public:
    int n;
    vi seg;
    int build(vi &nums,int l, int r, int node){
        if(l==r)return seg[node]=nums[l];
        int mid=(r+l)/2;
        int left = build(nums,left,mid,2*node+1);
        int right = build(nums,mid+1,r,2*node+2);
        return seg[node]=left+right;
    }
    int update(int ind,int val,int ss, int se, int node){
        if(ind<ss || ind>se)return seg[node];
        if(ss==se)return seg[node]=val;
        int mid=(se+ss)/2;
        int left=update(ind,val,ss,mid,2*node+1);
        int right=update(ind,val,mid+1,se,2*node+2);
        return seg[node]=left+right;
    }
    int sum(int l,int r,int ss, int se,int node){
        if(l>se || r<ss)return 0;
        if(l<=ss and r>=se)return seg[node];
        int mid=(se+ss)/2;
        int left=sum(l,r,ss,mid,2*node+1);
        int right=sum(l,r,mid+1,se,2*node+2);
        return left+right;
    }
    NumArray(vector<int>& nums) {
        n=nums.size();
        seg.resize(4*n);
        build(nums,0,n-1,0);
    }
    
    void update(int index, int val) {
        update(index,val,0,n-1,0);
    }
    
    int sumRange(int left, int right) {
        return sum(left,right,0,n-1,0);
    }
};
