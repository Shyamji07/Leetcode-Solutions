class BrowserHistory {
public:
    vector<string> history;
    int curr;  // the current we are in

    BrowserHistory(string homepage) {
        history.push_back(homepage);
        curr=0;
    }
    
    void visit(string url) {
        history.resize(curr+1); //erase all the next history ie can't move forward.
        history.push_back(url);
        curr++;
    }
    
    string back(int steps) {
        curr=max(0,curr-steps); // move back but should not be negative
        return history[curr];
    }
    
    string forward(int steps) {
        curr=min((int)history.size()-1,curr+steps); // can move till the most recent page ie the last element of our history
        return history[curr];
    }
};