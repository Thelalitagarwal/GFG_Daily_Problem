#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isPrime(int n)
    {
        for(int i = 2;i*i<=n;i++)
        {
            if(n%i==0) return false;
        }
        return true;
    }

    int firingEmployees(vector<int> &arr, int n){
        vector<vector<int>> adj;
        for(int i = 0;i<n;i++)
        {
            adj.push_back({arr[i], i+1});
        }
        vector<int> adjList[n+1];
        for(int i = 0;i<adj.size();i++)
        {
            adjList[adj[i][0]].push_back(adj[i][1]);
        }
        queue<pair<int,int>> Q;
        int startNode = adjList[0][0];
        Q.push({startNode, 0});
        int cnt = 0;
        vector<int> visited(n+1, 0);
        visited[startNode]=1;
        while(!Q.empty())
        {
            pair<int,int> front = Q.front();
            Q.pop();
            int node = front.first;
            int level = front.second;
            if(node!=startNode)
            {
                if(isPrime(node+level)) cnt++;
            }
            
            for(int i = 0;i<adjList[node].size();i++)
            {
                if(!visited[adjList[node][i]])
                {
                    visited[adjList[node][i]]=1;
                    Q.push({adjList[node][i], level+1});
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n,0);
        
        for(int i=0; i<n; i++)
            cin >> arr[i];

        Solution obj;
        cout << obj.firingEmployees(arr, n) << endl;
    }
    return 0;
}