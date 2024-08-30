// Leetcode no : 1905

class Solution {
    int n;
    int m;
    
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    bool BFS(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int i,int j,vector<vector<bool>>&vis){
       bool valid=true;
        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j]=true;
        while(!q.empty()){
                auto u=q.front();
                int x=u.first;
                int y=u.second;
                q.pop();
                if(grid1[x][y]!=1){
                    valid=false;
                }
                for(int k=0;k<4;k++){
                    int newX=x+dir[k][0];
                    int newY=y+dir[k][1];
                    if(newX<n && newX>=0 && newY<m && newY>=0 && !vis[newX][newY] && grid2[newX][newY]==1){
                        vis[newX][newY]=true;
                        q.push({newX,newY});
                    }
                }
        }
        return valid;
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n=grid1.size();
        m=grid1[0].size();
        int cnt=0;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==0){
                    vis[i][j]=true;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid2[i][j]==1){
                    if(BFS(grid1,grid2,i,j,vis)){
                        cnt++;
                    }
                    
                }
            }
        }

        return cnt;
    }
};
