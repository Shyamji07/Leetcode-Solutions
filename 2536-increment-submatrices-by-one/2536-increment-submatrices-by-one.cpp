class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        
        vector<vector<int>> temp(n, vector<int>(n,0));
        
        for(int i=0; i<queries.size(); i++){
            int toprow= queries[i][0];
            int leftcol= queries[i][1];
            int bottomrow= queries[i][2];
            int rightcol= queries[i][3];
            
           
            // prefix sum concept
            // basically , for every row toprow -> bottomrow, ist column of each row ( temp[j][leftcol]) will be done += (+1)
            // and the next column of the last column(except the last column, which we can ignore) of each row (i.e, temp[j][rightcol+1]) will be done += (-1)
            // so that we get our desired sums while doing cumulative sum at last...
            for(int j=toprow; j<=bottomrow; j++){
                temp[j][leftcol] +=1;
                if( rightcol<n-1)
                    temp[j][rightcol+1] +=-1;
            }
        }
        
        // for every row, calculate prefix sum 
        for(int i=0; i<n; i++)
            for(int j=1; j<n; j++)
                temp[i][j]+= temp[i][j-1];
    

        return temp;
    }
};