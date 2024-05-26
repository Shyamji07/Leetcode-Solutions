class Solution {
public:
    static bool comp(vector<int>a, vector<int>b){
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
         //sorting the courses based on the end day
    sort(courses.begin(),courses.end(),comp);
    
    //using priority queue to sort the elements so that we can check if we have found 
    //any small element before while traversing or not and if not then we interchange
    priority_queue<int> pq;
    int total = 0;
    for(auto &x : courses){
        int duration = x[0],end = x[1];
        
        //if course we selected completes before its end time then we add it to pq
        if(duration + total <= end)
        {
            total = total + duration;
            pq.push(duration);
        }
        //if ele at top of pq is greater than curr duration of selected course then it means we have to selecct the smaller one so increase no. to we pop top one and add this duration 
        //now before poppin we have subtract the duration of top element to not consider that in total time.
        else if(pq.size() && pq.top() > duration)
        {
            total = total + duration - pq.top();
            pq.pop();
            pq.push(duration);
        }
    }
    
    //returning elemetns in pq which are the best no. of courses that can be choosen
    return pq.size();
    }
};