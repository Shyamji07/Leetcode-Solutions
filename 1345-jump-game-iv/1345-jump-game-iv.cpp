class Solution {
public:
   int minJumps(vector<int>& arr) {
        
       unordered_map<int,vector<int>> mp;
        
       for(int i=0;i<arr.size();i++){
           mp[arr[i]].push_back(i);
       }
       
        queue<int> q;
        q.push(0);
        
        vector<int> dis(arr.size(),1e9);
        
        dis[0]=0;
        
        while(!q.empty()){
            
            int index=q.front();
            q.pop();
            
            if(index==arr.size() - 1) return dis[index];
            
            vector<int> &list=mp[arr[index]];
            list.push_back(index - 1);
            list.push_back(index + 1);
            
            
            for(auto  &x : list){
                
                if(x>=0 and x<arr.size() and dis[x]>dis[index] + 1){
                    dis[x] = dis[index] + 1;
                    q.push(x);
                }
            }
            list.clear();
        }
        
        return -1;
    }
};


// class Solution {
// public:
//     int minJumps(vector<int>& arr) 
//     {
//         int n = arr.size();
//         unordered_map<int, vector<int>>mp;
//         for (int i = 0; i < n; i++) mp[arr[i]].push_back(i);
        
//         queue<int>q;
//         vector<bool>visited(n, false);
//         q.push(0);
//         int steps = 0;
//         while(!q.empty())
//         {
//             int size = q.size();
//             while(size--)
//             {
//                 int currIdx = q.front();
//                 q.pop();
//                 if (currIdx == n - 1) return steps;
//                 //================================================================
//                 //EXPLORE ALL POSSIBLE OPTIONS
//                 if (currIdx + 1 < n && !visited[currIdx + 1])  //OPTION-1 (Move Back)
//                 {
//                     visited[currIdx + 1] = true;
//                     q.push(currIdx + 1);
//                 }
//                 if (currIdx - 1 >= 0 && !visited[currIdx - 1]) //OPTION-2 (Move Forward)
//                 {
//                     visited[currIdx - 1] = true;
//                     q.push(currIdx - 1);
//                 }
//                 for (int newIdx : mp[arr[currIdx]])  //OPTION-3 (Move to same valued idx)
//                 {                                 //newIdx coud be before currIdx or after currIdx
//                     if (!visited[newIdx]) 
//                     {
//                         visited[newIdx] = true;
//                         q.push(newIdx);
//                     }
//                 }
//                 //===================================================================
//                 mp[arr[currIdx]].clear();    //EXPLAINED BELOW :)
//             }
//             steps++;
//         }
//         return -1;
//     }
// };