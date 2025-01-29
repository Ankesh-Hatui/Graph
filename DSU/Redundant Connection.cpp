/*
* Leetcode : 684
* T.C : O(V+E)*V
* S.C : O(2*V)
*/

// Using DFS or BFS :
class Solution {
    bool BFS(unordered_map<int,vector<int>>adj,int u,int v,vector<bool>&seen){
        queue<int>q;
        q.push(u);
        seen[u]=true;

        while (!q.empty()){
            int node=q.front();
            if (node==v){
                return true;
            }
            q.pop();
            for (auto&el:adj[node]){
                if (!seen[el]){
                    seen[el]=true;
                    q.push(el);
                }
            }
        }
        return false;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();

        unordered_map<int,vector<int>>adj;
        vector<int>ans;
        vector<bool>visited(n,false);
        
        for (int i=0;i<n;i++){
            int u=edges[i][0];
            int v=edges[i][1];

            if (visited[u] && visited[v]){
                vector<bool>seen(n,false);
                if (BFS(adj,u,v,seen)){
                    ans={u,v};
                    break;
                }
            }
            visited[u]=true;
            visited[v]=true;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return ans;
    }
};
