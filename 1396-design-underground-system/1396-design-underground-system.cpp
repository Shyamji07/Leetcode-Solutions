class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>> users;
    unordered_map<string,pair<long int, int>> stations;
    
    UndergroundSystem() {
        users.clear();
        stations.clear();
    }
    
    void checkIn(int id, string s, int t) {
        users[id] = pair<string,int>(s,t);
    }
    
    void checkOut(int id, string s, int t) {
        auto i = users[id];
        string c = i.first + "#" + s;
        auto j = stations.find(c);
        if(j==stations.end()){
            stations.insert(make_pair(c, pair<long int, int>(0,0)));
        }
        stations[c].first += (t-i.second);
        (stations[c].second)++; 
        users.erase(id);
    }
    
    double getAverageTime(string s, string e) {
        double ans = 0;
        string t = s + "#" + e;
        auto j = stations.find(t);
         if(j!=stations.end()){
            ans = (double)(j->second.first)/(j->second.second);
        }
        return ans;
    }
};