#User function Template for python3
from typing import List

class Solution:
    
    def BFS(self,v,adj,indegree):
        q=[]
        for i in range(len(indegree)):
            if indegree[i]==0:
                q.append(i)
        
        cnt_node=0
        while q:
            node=q.pop(0)
            cnt_node+=1
            
            for el in adj[node]:
                indegree[el]-=1
                if indegree[el]==0:
                    q.append(el)
            
        
        if cnt_node==v:
            return True
        return False
            
    
    #Function to detect cycle in a directed graph.
    def isCyclic(self, V : int , adj : List[List[int]]) -> bool :
        # code here
        indegree=[0 for i in range(V)]
        
        for i in range(V):
            for el in adj[i]:
                indegree[el]+=1
        return not self.BFS(V,adj,indegree)
                

#{ 
 # Driver Code Starts
#Initial Template for Python 3

import sys

sys.setrecursionlimit(10**6)

if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        V, E = list(map(int, input().strip().split()))
        adj = [[] for i in range(V)]
        for i in range(E):
            a, b = map(int, input().strip().split())
            adj[a].append(b)
        ob = Solution()

        if ob.isCyclic(V, adj):
            print(1)
        else:
            print(0)

        print("~")
# } Driver Code Ends
