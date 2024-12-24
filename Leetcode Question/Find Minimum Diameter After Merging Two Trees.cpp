/*
* LeetCode : 3203
* T.C : O(N*4) 4 times DFS
* S.C : O(h) due to recursive stack where h is height of tree
*/

class Solution {
public:
    void DFS(unordered_map<int, vector<int>> &edges, vector<bool> &visited, int u, int cnt, int &maxi, int &endpoint) {
        visited[u] = true;
        if (cnt > maxi) {
            maxi = cnt;
            endpoint = u;
        }
        for (int node : edges[u]) {
            if (!visited[node]) {
                DFS(edges, visited, node, cnt + 1, maxi, endpoint);
            }
        }
    }

    // Function to find the diameter of the tree
    int findDiameter(unordered_map<int, vector<int>> &edges, int u) {
        vector<bool> visited(100000, false);
        int maxi = 0, endpoint = u;

        // First DFS to find the farthest node
        DFS(edges, visited, u, 0, maxi, endpoint);

        // Reset visited and run DFS from the farthest node
        fill(visited.begin(), visited.end(), false);
        maxi = 0;
        DFS(edges, visited, endpoint, 0, maxi, endpoint);

        return maxi;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int, vector<int>> Edges1, Edges2;

        // Build adjacency lists for both trees
        for (auto &li : edges1) {
            Edges1[li[0]].push_back(li[1]);
            Edges1[li[1]].push_back(li[0]);
        }
        for (auto &li : edges2) {
            Edges2[li[0]].push_back(li[1]);
            Edges2[li[1]].push_back(li[0]);
        }

        // Find the diameters of both trees
        int dia1 = findDiameter(Edges1, 1);
        int dia2 = findDiameter(Edges2, 1);

        // Calculate the resulting diameter after merging
        int ans1 = (dia1 + 1) / 2;
        int ans2 = (dia2 + 1) / 2;
        int ans = ans1 + ans2 + 1;

        return max(max(dia1, dia2), ans);
    }
    
};
