import queue
class Solution:
    def dfs(adj: List[List[int]],x:int,crvisit:List[bool],visit:List[bool]):
        visit[x] = True
        crvisit[x] = True
        for i in adj[x]:
            if(not visit[i]):
                if(Solution.dfs(adj,i,crvisit,visit)):
                    return True
            elif (crvisit[i] and visit[i]):
                return True
        
        crvisit[x]=False
        
        return False

    def canFinish(self, n: int, p: List[List[int]]) -> bool:
        adj = [[] for _ in range(n)]
        for i in range(0,len(p)):
            adj[p[i][0]].append(p[i][1])

        # print(adj)
        visit = [False for _ in range(len(adj))]
        crvisit = [False for _ in range(len(adj))]
        for i in range(0,n):
            if Solution.dfs(adj,i,crvisit,visit)==True:
                return False
        
        return True