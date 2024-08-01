//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    bool solvebyDFS(int u,vector<int>adj[],int parent,vector<bool>&visited){
        
        visited[u]=true;
        
        for(int& i:adj[u]){
            if(!visited[i]){
                if(solvebyDFS(i,adj,u,visited)){
                    return true;
                }
            }
            else{
                if(parent!=i){
                    return true;
                }
            }
            
        }
        return false;
    }
    
    
    bool solveByBFS(int u,vector<int>adj[],vector<bool>&visited){
        visited[u]=true;
        queue<pair<int,int>>q;
        q.push(make_pair(u,-1));
        
        while(!q.empty()){
            int n=q.size();
            //while(n--){
                pair<int,int>t=q.front();
                q.pop();
                int v=t.first;
                int p=t.second;
                for(int& it:adj[v]){
                    
                    if(it==p){
                        continue;
                    }
                    if(visited[it]){
                        return true;
                    }
                    
                    visited[it]=true;
                    q.push(make_pair(it,v));
                        
                }
        }
        
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool>visited(V,false);
        
        for(int i=0;i<V;i++){
            // if(!visited[i] && solvebyDFS(i,adj,-1,visited)){
                
            //     return true;
                
            // }
                if(!visited[i] && solveByBFS(i,adj,-1,visited)){
                
                return true;
                
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
