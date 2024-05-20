class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        s = sorted(set(nums))
        temp =1
        count =0
        if len(s)==0 or len(s)==1:
            return len(s)
        for i in range(len(s)-1):
            if s[i]+1==s[i+1]:
                temp+=1
            else:
                temp=1
            count = max(count,temp)
        return count
        