// Question no: 947
/* using DSU */

class Solution{
    vector<int>parent;
    vector<int>rank;
    int find(int a){
        if(parent[a]!=a){
            parent[a]=find(parent[a]);
        }
        return parent[a];
    }
    void unin(int a,int b)
    {

        int x=find(a);
        int y=find(b);

        if(x==y){
            return;
        }
        if(rank[x]>=rank[y]){
            parent[y]=x;
        }
        else if(rank[x]<rank[y]){
            parent[x]=y;
        }

    }


public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<stones.size();i++){
            parent[i]=i;
            rank[i]=1;
        }

        vector<vector<int>>grid(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    unin(i,j);
                }
            }
        }
        int Groups=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i){
                Groups++;
            }
        }

        return n-Groups;
    }
};
