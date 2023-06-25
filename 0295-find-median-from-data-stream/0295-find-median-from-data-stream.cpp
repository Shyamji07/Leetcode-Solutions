class MedianFinder {
public:
    priority_queue<int>p;
    priority_queue<int,vector<int>,greater<int>>q;
    MedianFinder() {
    }
    void addNum(int num) {
        int l=p.size(),r=q.size();
        if(l==0){ //case1
            p.push(num);
        }
        else if(l==r){//case2
            if(num<q.top())p.push(num);
            else{
                p.push(q.top());
                q.pop();
                q.push(num);
            }
        }
        else{  //case3
                if(num>=p.top())q.push(num);
                else{
                    q.push(p.top());
                    p.pop();
                    p.push(num);
                }
        }
    }
    
    double findMedian() {
         int l=p.size(),r=q.size();
        if(l>r){
            return double(p.top());
        }
        else return (double(p.top())+double(q.top()))/2;
    }
};
