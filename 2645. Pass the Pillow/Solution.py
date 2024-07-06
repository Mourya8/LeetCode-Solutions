class Solution:
    def passThePillow(self, n: int, time: int) -> int:
        direction = 1
        start = 1
        while time>0:
            if time > 0 and start == n:
                direction = -1
            elif time > 0  and start == 1:
                direction = 1
            start +=direction
            time-=1
        
        return start
        