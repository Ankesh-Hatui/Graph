/*
* Leetcode : 1091
* T.C : O(2^n*m)
* S.C : O(N*M)
*/

// TLE : DFS

class Solution {
    vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{-1,-1},{1,-1}};
    int n,m;
    void DFS(vector<vector<int>>& grid,vector<int>&cost,vector<vector<bool>>&visited,int curr,int r,int c){
        visited[r][c]=true;
        if (r==n-1 && c==m-1){
            cost.push_back(curr+1);
            visited[r][c]=false;
            return;
        }
        for (auto&row:dir){
            int newR=r+row[0];
            int newC=c+row[1];
            if (newR<n && newR>=0 && newC<m && newC>=0 && !visited[newR][newC] && grid[newR][newC]!=1){
                DFS(grid,cost,visited,curr+1,newR,newC);
            }
        }
        visited[r][c]=false;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        if (grid[0][0]==1 || grid[n-1][m-1]==1){
            return -1;
        }
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        vector<int>cost;
        DFS(grid,cost,visited,0,0,0);
        if (cost.size()==0){
            return -1;
        }
        return *min_element(cost.begin(),cost.end());
    }
};
