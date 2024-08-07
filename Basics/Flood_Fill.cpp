//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    // void DFS(vector<vector<int>>& image, int sr, int sc, int newColor,int n,int m){
    //     if(image[sr][sc]==0 || image[sr][sc]==newColor){
    //         return;
    //     }
        
    //     if(sr<n-1 && image[sr+1][sc]==image[sr][sc]  && image[sr+1][sc]!=newColor){
    //         DFS(image,sr+1,sc,newColor,n,m);
    //     }
        
    //     if(sr>0 && image[sr-1][sc]==image[sr][sc] && image[sr-1][sc]!=newColor){
    //         DFS(image,sr-1,sc,newColor,n,m);
    //     }
        
    //     if(sc<m-1 && image[sr][sc+1]==image[sr][sc] && image[sr][sc+1]!=newColor){
    //         DFS(image,sr,sc+1,newColor,n,m);
    //     }
        
    //     if(sc>0 && image[sr][sc-1]==image[sr][sc] && image[sr][sc-1]!=newColor){
    //         DFS(image,sr,sc-1,newColor,n,m);
    //     }
        
    //     image[sr][sc]=newColor;
    //     return;
    // }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        
        int n=image.size();
        int m=image[0].size();
        
        // queue<pair<int,int>>q;
        // q.push(make_pair(sr,sc));
       
        
        // while(!q.empty()){
        //     int r=q.front().first;
        //     int c=q.front().second;
        //     q.pop();
        
        //     if(r<n-1 && image[r+1][c]==image[r][c] && image[r+1][c]!=newColor ){
        //         q.push(make_pair(r+1,c));
        //     }
        //     if(r>0 && image[r-1][c]==image[r][c] && image[r-1][c]!=newColor){
        //         q.push(make_pair(r-1,c));
        //     }
        //     if(c<m-1 && image[r][c+1]==image[r][c] && image[r][c+1]!=newColor){
        //         q.push(make_pair(r,c+1));
        //     }
        //     if(c>0 && image[r][c-1]==image[r][c]&& image[r][c-1]!=newColor){
        //         q.push(make_pair(r,c-1));
                
        //     }
        //     image[r][c]=newColor;
        // }
        
        // return image;
        
        DFS(image,sr,sc,newColor,n,m);
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
