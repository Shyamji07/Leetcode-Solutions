class Solution {
public:
    // vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
    //     int n = obstacles.size();
    //     vector<int> res(n, 1);
    //     vector<int> v;
    //     for(int i=0; i<n; i++) {
    //         int tr = upper_bound(v.begin(),v.end(),obstacles[i]) - v.begin();
    //         if(tr == v.size()) v.push_back(obstacles[i]);
    //         else v[tr] = obstacles[i];
    //         res[i] = tr + 1;
    //     }
    //     return res;
    // }
    
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& A) {
        vector<int> res, mono;
        for (int a : A) {
            int l = 0, r = mono.size();
            while (l < r) {
                int m = (l + r) / 2;
                if (mono[m] <= a)
                    l = m + 1;
                else
                    r = m;
            }
            res.push_back(l + 1);
            if (mono.size() == l)
                mono.push_back(a);
            mono[l] = a;
        }
        return res;
    }
};
