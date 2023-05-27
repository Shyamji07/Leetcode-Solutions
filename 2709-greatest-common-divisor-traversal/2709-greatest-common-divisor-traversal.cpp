// class Solution {
// public:
//     class UnionFind {
// private:
//     vector<int> parent;
//     vector<int> rank;

// public:
//     UnionFind(int n) {
//         parent.resize(n);
//         rank.resize(n, 1);
//         for (int i = 0; i < n; i++) {
//             parent[i] = i;
//         }
//     }

//     int find(int x) {
//         if (parent[x] != x) {
//             parent[x] = find(parent[x]);
//         }
//         return parent[x];
//     }

//     void unite(int x, int y) {
//         int rootX = find(x);
//         int rootY = find(y);

//         if (rootX != rootY) {
//             if (rank[rootX] < rank[rootY]) {
//                 parent[rootX] = rootY;
//             } else if (rank[rootX] > rank[rootY]) {
//                 parent[rootY] = rootX;
//             } else {
//                 parent[rootX] = rootY;
//                 rank[rootY]++;
//             }
//         }
//     }
// };

// bool canTraverseAllPairs(vector<int>& nums) {
//     int n = nums.size();
//     UnionFind uf(n);

//     unordered_map<int, vector<int>> factors;

//     for (int i = 0; i < n; i++) {
//         for (int j = 2; j * j <= nums[i]; j++) {
//             if (nums[i] % j == 0) {
//                 factors[j].push_back(i);
//                 while (nums[i] % j == 0) {
//                     nums[i] /= j;
//                 }
//             }
//         }
//         if (nums[i] > 1) {
//             factors[nums[i]].push_back(i);
//         }
//     }

//     for (auto& factorPair : factors) {
//         vector<int>& indices = factorPair.second;
//         for (int i = 1; i < indices.size(); i++) {
//             uf.unite(indices[i - 1], indices[i]);
//         }
//     }

//     int root = uf.find(0);
//     for (int i = 1; i < n; i++) {
//         if (uf.find(i) != root) {
//             return false;
//         }
//     }

//     return true;
// }
 
// };

constexpr int maxn = 100000;
vector<int> pd[maxn + 1];
class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        if (pd[2].empty()) {
            for (int i = 2; i <= maxn; i += 1) {
                if (pd[i].empty()) {
                    for (int j = i; j <= maxn; j += i) {
                        pd[j].push_back(i);
                    }
                }
            }
        }
        map<int, vector<int>> mp;
        int n = nums.size();
        vector<vector<int>> g(n);
        for (int i = 0; i < n; i += 1) {
            for (int p : pd[nums[i]]) {
                mp[p].push_back(i);
            }
        }
        for (auto& [x, v] : mp) {
            for (int i = 1; i < v.size(); i += 1) {
                g[v[0]].push_back(v[i]);
                g[v[i]].push_back(v[0]);
            }
        }
        vector<int> vis(n);
        int m = 0;
        function<void(int)> dfs = [&](int u) {
            if (vis[u]) {
                return;
            }
            m += vis[u] = 1;
            for (int v : g[u]) {
                dfs(v);
            }
        };
        dfs(0);
        return n == m;
    }
};