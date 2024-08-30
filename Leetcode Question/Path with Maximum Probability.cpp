// Question Link : https://leetcode.com/problems/path-with-maximum-probability/description/?envType=daily-question&envId=2024-08-27
// Question no : 1514
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        priority_queue<pair<double,int>,vector<pair<double,int>>>pq;
        vector<double>ans(n,0.0);

        pq.push({1.0,start_node});
        ans[start_node]=1.0;

        while(!pq.empty()){
            auto u=pq.top();
            int node=u.second;
            double prob=u.first;
            pq.pop();
            for(auto& it:adj[node]){
                int neigh=it.first;
                double prblty=it.second*prob;
                if(ans[neigh]<prblty){
                    ans[neigh]=prblty;
                    pq.push({prblty,neigh});
                }
            }
        }

        return ans[end_node];
    }
};
