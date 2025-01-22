/*
* Leetcode : 1765
* T.C : O(M*N)
* S.C : 2*O(M*N)
*/

class Solution {
    void BFS(vector<vector<int>>&height,vector<vector<bool>>&visited,vector<pair<int,int>>&srcs){
        queue<pair<int,int>>q;
        for (int i=0;i<srcs.size();i++){
            auto p=srcs[i];
            //cout<<p.first<<" "<<p.second<<"\n";
            q.push(p);
        }
        while (!q.empty()){
            int n=q.size();
            for (int i=0;i<n;i++){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                vector<pair<int,int>>dir={{1,0},{-1,0},{0,-1},{0,1}};
                for (auto&p:dir){
                    int newR=r+p.first;
                    int newC=c+p.second;

                    if (newR>=0 && newR<height.size() && newC>=0 && newC<height[0].size()){
                        if (!visited[newR][newC]){
                            visited[newR][newC]=true;
                            height[newR][newC]=height[r][c]+1;
                            q.push({newR,newC});
                        }
                    }
                }

            }      
        }
    }
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();
        vector<vector<int>>height(n,vector<int>(m,0));

        // Sources To start MultiSrc BFS
        vector<pair<int,int>>srcs;
        //To keep record of travered cells
        vector<vector<bool>>visited(n,vector<bool>(m,false));

        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (isWater[i][j]==1){
                    visited[i][j]=true;
                    srcs.push_back({i,j});
                    height[i][j]=0;
                }
            }
        }

        BFS(height,visited,srcs);
        return height;
    }
};
