class RandomizedSet {
public:
    vector<int>arr;
    unordered_map<int, int> mp;
    RandomizedSet() { }
    
    bool insert(int val) {   
        auto it=mp.find(val);
        if(it == mp.end()){
            arr.push_back(val);
            mp[val]=arr.size()-1;
            return true;
        }
        return false;
    }
    bool remove(int val) {
        auto it=mp.find(val);
        if(it != mp.end()){
            arr[it->second]=arr.back();
            arr.pop_back();
            mp[arr[it->second]]=it->second;
            mp.erase(val);
            return true;
        }
        return false;
    }
    int getRandom() {
        return arr[rand()%arr.size()];
    }
};
