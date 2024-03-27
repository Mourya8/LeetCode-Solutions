class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort()
        count =1
        current = [points[0][0],points[0][1]]
        for i in range(1,len(points)):
            if current[1]<points[i][0]:
                count+=1
                current[0]=points[i][0]
                current[1]=points[i][1]
            else:
                current[0]=max(current[0],points[i][0])
                current[1]=min(current[1],points[i][1])
        
        return count