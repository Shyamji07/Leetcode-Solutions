class Solution {
public:
    int bestClosingTime(string arr) {
        int a=0,b=0;
        for(auto c:arr){
            if(c=='Y')a++;
            else b++;
        }
        int res=0,minimum=a,cnt=a;
        for(int i=0;i<arr.size();i++){
            if(arr[i]=='Y'){
                cnt--;
                if(minimum>cnt){
                    minimum=cnt;
                    res=i+1;
                }
            }
            else {
                cnt++;
            }
        }
        return res;
    }
};