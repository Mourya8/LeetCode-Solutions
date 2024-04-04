from itertools import permutations
class Solution:
    def next_permutation(s):
        # Find the largest index k such that s[k] < s[k+1]
        k = len(s) - 2
        while k >= 0 and s[k] >= s[k + 1]:
            k -= 1
        if k == -1:
            return None  # Last permutation reached, no next permutation
    
        # Find the largest index l greater than k such that s[k] < s[l]
        l = len(s) - 1
        while s[l] <= s[k]:
            l -= 1
    
        # Swap s[k] and s[l]
        s = list(s)
        s[k], s[l] = s[l], s[k]
    
        # Reverse the sequence from s[k+1:] to get the next permutation
        s[k + 1:] = reversed(s[k + 1:])
    
        return ''.join(s)


    def kthSmallestPath(self, destination: List[int], k: int) -> str:
        m, n = destination
        base = ["H" for i in range(m+n)] 
        t = k-1 # num of instructions smaller than the kth smallest one
        v_left = m # how many "V" left to be put to the right side
        
        
        for i in range(m+n):
            if comb(m+n-i-1, v_left) <= t:
                base[i] = "V"
                t -= comb(m+n-i-1, v_left)
                v_left -= 1

                
            #if t == 0, that means the left "V" should all be put to the rightmost places
            if t == 0:
                for j in range(m+n-v_left, m+n):
                    base[j] = "V"
                break
        
        return "".join(base)