'''
' Basic Question
' Leetcode Preminum
' Read Notes or watch Codestorywithmik video to understand 
'''

class Graph:
    def __init__(self,V):
        self.v=V
        self.edges={i:[] for i in range(V+1)}
    
    def DFS(self,u,visited,cnt,result):
        visited[u]=True
        if (result['maxi']<cnt):
            result['maxi']=cnt
            result['endpoint']=u

        for node in self.edges[u]:
            if not visited[node]:
                self.DFS(node,visited,cnt+1,result)
    def Diameter(self,edges,u):
        result={'maxi':0,'endpoint':u};
        visited=[False]*(self.v+1)
        self.DFS(u,visited,0,result)
        print(result['endpoint'])

G=Graph(6)
G.edges[1]=[2,3,5]
G.edges[2]=[1]
G.edges[3]=[1,4]
G.edges[4]=[3]
G.edges[5]=[1,6]
G.edges[6]=[5]
G.Diameter(G.edges,4)




