from itertools import permutations
class Solution:


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