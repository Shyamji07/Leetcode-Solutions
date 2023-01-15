class Solution {
public:
     int get(int n)
    {
        int sum = 0;
        while (n != 0) {
            sum = sum + n % 10;
            n = n / 10;
        }
        return sum;
    }

    int differenceOfSum(vector<int>& arr) {
        long long sum=0,di=0;
        for(auto a:arr){
            sum+=a;
            di+=get(a);
        }
        return abs(di-sum);
    }
};