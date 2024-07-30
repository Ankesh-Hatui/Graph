//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    void DFS(int v,unordered_map<int,vector<int>>&ad,vector<bool>&visited,vector<int>&ans){
        if(visited[v]==true){
            return;
        }
        visited[v]=true;
        ans.push_back(v);
        for(int &i:ad[v]){
            //ans.push_back(i);
            if(!visited[i])
                DFS(i,ad,visited,ans);
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        unordered_map<int,vector<int>>ad;
        for(int i=0;i<V;i++){
            for(auto v=adj[i].begin();v!=adj[i].end();v++){
                ad[i].push_back(*v);
            }
        }
        vector<int>ans;
        vector<bool>visited(V,false);
        DFS(0,ad,visited,ans);
        return ans;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends