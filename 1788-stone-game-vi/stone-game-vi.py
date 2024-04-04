class Solution:
    def stoneGameVI(self, aliceValues: List[int], bobValues: List[int]) -> int:
        aliceList =[(aliceValues[i]+bobValues[i],i) for i in range(0,len(aliceValues))]
        aliceList.sort(reverse=True)
        aliceTotal = 0
        bobTotal= 0
        for i in range(0,len(aliceValues)):
            if(i%2==0):
                aliceTotal+=aliceValues[aliceList[i][1]]
            else:
                bobTotal+=bobValues[aliceList[i][1]]
        
        print(aliceTotal)
        
        if aliceTotal==bobTotal:
            return 0
        
        return 1 if aliceTotal>bobTotal else -1
