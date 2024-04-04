class Solution:
    def miceAndCheese(self, reward1: List[int], reward2: List[int], k: int) -> int:
        diff = [i - j for i, j in zip(reward1, reward2)]
        diff.sort(reverse=True)
        r=0
        for i in reward2:
            r+=i
        for i in range(0,k):
            r=r+diff[i]
        return r
