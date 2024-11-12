"""
LeetCode : 785
T.C : O(V+E) when we enqued every Node V at most once and find neighbours 
visit Every Edges at most once
S.C : O(V)
"""
class Solution:
    def BFS(self,src,visited,graph):

        color=[-1 for i in range(101)]

        q=[]
        q.append(src)
        color[src]=0
        visited[src]=True
        while q:
            node=q.pop(0)
            for nd in graph[node]:
                #for nd in el:
                if (color[nd]==-1):
                    color[nd]=1-color[node]
                else:
                    if color[nd]==color[node]:
                        return False
                    else:
                        continue
                q.append(nd)
                visited[nd]=True
        return True

    def isBipartite(self, graph: List[List[int]]) -> bool:
        visited=[False for i in range(101)]
        for li in graph:
            for node in li:
                if not visited[node]:
                    if not self.BFS(node,visited,graph):
                        return False
        return True
