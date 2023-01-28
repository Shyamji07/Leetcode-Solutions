class SummaryRanges {
public:
    SummaryRanges() {
        
    }
    void addNum(int value) {
        auto it = mp.lower_bound(value);
        bool flag = false;
        if(it != mp.begin()) {
            auto previous = it;
            --previous;
            if(previous->second + 1 >= value) {
                flag = true;
                previous->second = max(previous->second, value);
            }
        }

        if(it != mp.end()) {
            if(it->first - 1 <= value) {
                if(flag) {
                    auto previous = it;
                    --previous;
                    if(previous->second >= it->first - 1) {
                        previous->second = max(previous->second, it->second);
                        mp.erase(it);
                    }
                } else {
                    flag = true;
                    if(it->first != value) {
                        pair<int, int> p = *it;
                        p.first = min(p.first, value);
                        it = mp.insert(it, p);
                        ++it;
                        if(it != mp.end())
                            mp.erase(it);
                    }
                }
            }
        }
        if(!flag)
            mp.insert(it, {value, value});
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for(auto const & p : mp)
            ans.push_back({p.first, p.second});
        return ans;
    }

    map<int, int> mp;
};