class Solution:
    def BFS(self,adjList,ans,indegree):
        q=[]
        for i in range(len(indegree)):
            if indegree[i]==0:
                q.append(i)
        
        while q:
            node = q.pop(0)
            ans.append(node)
            for nd in adjList[node]:
                indegree[nd]-=1
                if indegree[nd]==0:
                    q.append(nd)
            
            
    #Function to return list containing vertices in Topological order.
    def topologicalSort(self,adj):
        # Code here
        adjList={i:[] for i in range(len(adj))}
        ans=[]
        indegree=[0 for i in range(len(adj))]
        for i in range(len(adj)):
            for j in adj[i]:
                adjList[i].append(j)
                indegree[j]+=1
        self.BFS(adjList,ans,indegree)
        return ans
#{ 
 # Driver Code Starts
# Driver Program

import sys

sys.setrecursionlimit(10**6)


def check(graph, N, res):
    if N != len(res):
        return False
    map = [0] * N
    for i in range(N):
        map[res[i]] = i
    for i in range(N):
        for v in graph[i]:
            if map[i] > map[v]:
                return False
    return True


if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        e, N = list(map(int, input().strip().split()))
        adj = [[] for i in range(N)]

        for i in range(e):
            u, v = map(int, input().split())
            adj[u].append(v)

        ob = Solution()

        res = ob.topologicalSort(adj)

        if check(adj, N, res):
            print(1)
        else:
            print(0)
        print("~")
# Contributed By: Harshit Sidhwa

# } Driver Code Ends
