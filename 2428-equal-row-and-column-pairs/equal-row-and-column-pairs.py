class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        count =0
        d = {}
        for l in grid:
            s = ','.join(map(str, l))
            if s in d:
                d[s]=d[s]+1
            else:
                d[s]=1
        
        for i in range(0,len(grid[0])):
            t=[]
            for j in range(0,len(grid)):
                t.append(grid[j][i])
            s =','.join(map(str, t))
            if s in d:
                count =count + d[s]
        
        return count
