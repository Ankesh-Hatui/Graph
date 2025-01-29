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

//Approach-3 (DSU - Union Find with Path compression)
//T.C : O(n * alpha(n))
//S.C : O(n)

class Solution {
    int find(vector<int>&parent,int u){
        if (parent[u]!=u){
            parent[u]=find(parent,parent[u]);
        }
        return parent[u];
    }
    void uni(vector<int>&parent,vector<int>&rank,int u,int v){
        int par_u=find(parent,u);
        int par_v=find(parent,v);

        if (par_u==par_v){
            return;
        }
        if (rank[par_u]>rank[par_v]){
            parent[par_v]=par_u;
        }
        else if (rank[par_v]>rank[par_u]){
            parent[par_u]=par_v;
        }
        else{
            parent[par_v]=par_u;
            rank[par_u]++;
        }
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>parent(n+1),rank(n+1,0);
        vector<int>ans;
        for (int i=0;i<=n;i++){
            parent[i]=i;
        }

        for (int i=0;i<n;i++){
            int u=edges[i][0];
            int v=edges[i][1];

            int par_u=find(parent,u);
            int par_v=find(parent,v);

            if (par_u==par_v){
                ans={u,v};
                break;
            }
            else{
                uni(parent,rank,u,v);
            }
        }

        return ans;

    }
};
