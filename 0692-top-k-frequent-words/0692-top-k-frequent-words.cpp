class Solution {
public:
    vector<string> topKFrequent(vector<string>& nums, int k) {
    unordered_map<string,int>mp;
        vector<string>v;
        for(auto c:nums)mp[c]++;
        priority_queue<pair<int,string>,vector<pair<int,string>>,MyComp>pq;
        for(auto m:mp){
            pq.push({m.second,m.first});
            if(pq.size()>k)pq.pop();
        }
        while(!pq.empty()){
            pair<int,string>temp=pq.top();
            v.emplace(v.begin(),temp.second);
            pq.pop();
        }
        return v;
    }
    private:
     struct MyComp {
        bool operator() (const pair<int, string>& a, const pair<int, string>& b) {
            if(a.first != b.first) {
                return a.first > b.first;
            }
            else {
                return a.second < b.second;
            }
        }
    };

};

// class Solution {
// public:
//     vector<string> topKFrequent(vector<string>& words, int k) {
//         unordered_map<string, int> hashmap;
//         for(string& word : words) {
//             hashmap[word] += 1;
//         }
//         priority_queue<pair<int, string>, vector<pair<int, string>>, MyComp> pq;
//         for(auto it = hashmap.begin(); it != hashmap.end(); ++it) {
//             pq.push(make_pair(it->second, it->first));
//             if(pq.size() > k) pq.pop();
//         }
//         vector<string> res;
//         while(!pq.empty()) {
//             res.insert(res.begin(), pq.top().second);
//             pq.pop();
//         }
//         return res;
//     }
// private:
//     struct MyComp {
//         bool operator() (const pair<int, string>& a, const pair<int, string>& b) {
//             if(a.first != b.first) {
//                 return a.first > b.first;
//             }
//             else {
//                 return a.second < b.second;
//             }
//         }
//     };
// };