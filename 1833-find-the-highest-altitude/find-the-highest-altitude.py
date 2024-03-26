class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        tempmax=0
        alt=0
        for i in gain:
            alt=alt+i
            tempmax=max(tempmax,alt)
        
        return tempmax
        