class MyHashMap {
public:
    // data members -->
    vector<list<pair<int,int>>> map;
    int size;
    
    MyHashMap() {
        // initialize the data members :
        size = 100;
        map.resize(size);
    }
    
    int hash (int key){
        return key % size;
    }
    
    auto search (int key){
        int i = hash(key);
        auto it = map[i].begin();
        while (it != map[i].end()){
            if(it->first == key) return it;
            it++;
        }
        return it;
    }
    
    void put(int key, int value) {
        int i = hash(key);
        remove(key);
        map[i].push_back({key,value});
    }
    
    int get(int key) {
        int i = hash(key);
        auto element = search(key);
        if(element == map[i].end()){
            return -1;
        }
        else{
            return element->second;
        }
    }
    
    void remove(int key) {
        int i = hash(key);
        auto element = search(key);
        if(element != map[i].end()){
            map[i].erase(element);
        }
    }
};
