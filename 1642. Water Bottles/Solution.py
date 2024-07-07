class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        r = numBottles
        while(numBottles>=numExchange):
            temp = numBottles//numExchange
            tempr = numBottles%numExchange
            r +=temp
            numBottles = temp+tempr
            # print(numBottles,temp,tempr,r)
        
        return int(r)