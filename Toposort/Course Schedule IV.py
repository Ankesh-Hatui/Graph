'''
* Leetcode : 1462
* T.C : O(V+E)
* S.C : 3*O(V)
'''
class Solution:
    def topoSort(self,adj,d,indegree):
        q=[]
        for i in range(len(indegree)):
            if indegree[i]==0:
                q.append(i)

        while q:
            node=q.pop(0)
            for el in adj[node]:
                indegree[el]-=1
                d[el].add(node)
                d[el].update(d[node])
                if indegree[el]==0:
                    q.append(el)
        
    def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
        d={i:set() for i in range(numCourses)}
        indegree=[0 for _ in range(numCourses)]
        adj={i:[] for i in range(numCourses)}
        for li in prerequisites:
            f=li[0]
            s=li[1]
            indegree[s]+=1
            adj[f].append(s)
        self.topoSort(adj,d,indegree)
        print(d)
        ans=[]
        for li in queries:
            f=li[0]
            s=li[1]
            if f in d[s]:
                ans.append(True)
            else:
                ans.append(False)
        return ans
        
