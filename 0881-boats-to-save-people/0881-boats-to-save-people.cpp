class Solution {
public:
    int numRescueBoats(vector<int>& p, int lim) {
        int count=0;
        sort(p.begin(),p.end());   //sort the given vector;
        int l=0,r=p.size();
        // if(r==1 and p[0]<=lim)return 1;
        while(l<r){                    //  while left hand value is less than right most value
            if(p[r-1]+p[l]<=lim){    //case-1 when they both can go on same boat
                count++;              // increase count of number of boats
                l++;r--;            //shift pointer to other people
            }
           else if(p[r-1]+p[l]>lim){  //case-1 when they both can't go on same boat so send right most one becasuse may be light one can manage eith a person who has lees weight than right most one;
                count++;              // increase count of number of boats
                r--;                 //only right most person will travel
            }
        }
        return count;
    }
};