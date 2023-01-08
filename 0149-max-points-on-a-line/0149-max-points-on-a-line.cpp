class Solution {
public:
  
    void simplify(int & x,int &y)
    {
        int d; 
        d = __gcd(x, y); 

        x = x / d; 
        y = y / d; 
    }
    int maxPoints(vector<vector<int>>& points) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        int omax=0;
        for(int i=0;i<points.size();i++)
        {
            unordered_map<string,int>map;
            int cmax=0;
            int count=1;
            for(int j=i+1;j<points.size();j++)
            {
                
                if(points[i][0]==points[j][0]&&points[i][1]==points[j][1])
                {
                    count++;
                }
                else
                {
                    int nr=(points[j][1]-points[i][1]);
                    int dr=(points[i][0]-points[j][0]);
                    simplify(nr,dr);
                    string fin=to_string(nr)+"#"+to_string(dr);
                    map[fin]++;
                    cmax=max(cmax,map[fin]);
                }
                
            }
            omax=max(omax,cmax+count);
        }
        return omax;
    }
};