class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>visited(n,vector<int>(m,0));

        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    visited[i][j]=2;
                }
            }
        }

        int time_required=0;

        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int time=q.front().second;

            q.pop();

            
                if(r>0 && grid[r-1][c]!=0 && visited[r-1][c]!=2){
                    q.push({{r-1,c},time+1});
                    visited[r-1][c]=2;
                }
                if(r<n-1 && grid[r+1][c]!=0 && visited[r+1][c]!=2){
                    q.push({{r+1,c},time+1});
                    visited[r+1][c]=2;
                }
            
                if(c>0 && grid[r][c-1]!=0 && visited[r][c-1]!=2){
                    q.push({{r,c-1},time+1});
                    visited[r][c-1]=2;
                }
                if(c<m-1 && grid[r][c+1]!=0 && visited[r][c+1]!=2){
                    q.push({{r,c+1},time+1});
                    visited[r][c+1]=2;
                }
           

            time_required=time;
                    
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0 && grid[i][j]==1){
                    return -1;
                }
            }
        }

        return time_required;
    }
};
