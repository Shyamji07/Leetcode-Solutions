//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
         vector<stack<int>> s;
    vector<queue<int>> q;
 
    // initializing both list with empty stack and queue
    for (int i = 0; i <= n; i++)
    {
        s.push_back(stack<int>());
        queue<int> queue;
        q.push_back(queue);
    }
 
    // add all nodes of tree 1 to list of stack and tree 2 to list of queue
    for (int i = 0; i < 2 * e; i += 2)
    {
        s[A[i]].push(A[i + 1]);
        q[B[i]].push(B[i + 1]);
    }
 
    // now take out the stack and queues
    // for each of the nodes and compare them
    // one by one
    for (int i = 1; i <= n; i++)
    {
        while (!s[i].empty() && !q[i].empty())
        {
            int a = s[i].top();
            s[i].pop();
            int b = q[i].front();
            q[i].pop();
 
            if (a != b)
            {
                return 0;
            }
        }
    }
 
    return 1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        
        cin>>n>>e;
        int A[2*e], B[2*e];
        
        for(int i=0; i<2*e; i++)
            cin>>A[i];
            
        for(int i=0; i<2*e; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.checkMirrorTree(n,e,A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends