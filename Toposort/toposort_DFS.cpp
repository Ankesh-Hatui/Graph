class Solution
{
    
    void topoSortDFS(int v,vector<int>adj[],vector<bool>&vis,stack<int>&st,int u){
        vis[u]=true;
        // you have to push all ajacency then parent 
        for(auto next:adj[u]){
            if(!vis[next]){
                topoSortDFS(v,adj,vis,st,next);
            }
        }
        st.push(u);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int v, vector<int> adj[]) 
	{
	    // code here
	    vector<int>ans;
	    stack<int>st;
	    vector<bool>vis(v,false);
	    for(int i=0;i<v;i++){
	        if(!vis[i]){
	            topoSortDFS(v,adj,vis,st,i);
	        }
	    }
	    
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    
	    return ans;
	}
};
