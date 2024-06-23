class Solution:
    def minimumArea(self, grid: List[List[int]]) -> int:
        minx=1001
        miny = 1001
        maxx= -1
        maxy = -1
        for i in range(0,len(grid)):
            for j in range(0,len(grid[0])):
                if grid[i][j]==1:
                    minx = min(minx,i)
                    miny = min(miny,j)
                    maxx = max(maxx,i)
                    maxy = max(maxy,j)


        if minx == 1001 and miny == 1001 and maxx == -1 and maxy == -1:
            return 0

        x = maxx - minx +1
        y = maxy - miny +1
        return x * y
        