'''
* Leetcode : 1267
* T.C : O(N*M)
* S.C : O(N*M)
'''
class Solution:
    def countServers(self, grid: List[List[int]]) -> int:
        n=len(grid)
        m=len(grid[0])
        row={i:0 for i in range(n)}
        col={i:0 for i in range(m)}

        for i in range(n):
            for j in range(m):
                if grid[i][j]==1:
                    row[i]+=1
                    col[j]+=1
        ans=0
        for i in range(n):
            for j in range(m):
                if grid[i][j]==1 and (row[i]>1 or col[j]>1):
                    ans+=1
        return ans
