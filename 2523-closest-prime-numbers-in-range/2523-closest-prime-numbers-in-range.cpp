class Solution {
public:
    vector<int>v;
    void findPrimes(int a, int b){
        if (a <= 2) {
        a = 2;
        if (b >= 2) {
            v.push_back(a);
            a++;
        }
    }

    if (a % 2 == 0)
        a++;
    for (int i = a; i <= b; i = i + 2) {
        bool flag = 1;
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }


        if (flag == 1){
          if(i==1)
            continue;
          else
            v.push_back(i);
        }
    }
    }
    vector<int> closestPrimes(int l, int r) {
        findPrimes(l,r);
        if(v.size()<2)return {-1,-1};
        int temp1=v[0];
        int temp2=v[1];
        int minimum=temp2-temp1;
        for(int i=2;i<v.size();i++){
            if(v[i]-v[i-1]<minimum){
                temp1=v[i-1];
                temp2=v[i];
                minimum=min(minimum,temp2-temp1);
            }
        }
        return {temp1,temp2};
    }
};