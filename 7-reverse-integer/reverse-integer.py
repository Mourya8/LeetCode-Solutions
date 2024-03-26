import sys

class Solution:
    def reverse(self, x: int) -> int:
        b=False
        if x < 0:
            b=True

        s = str(abs(x))
        s=s[::-1]
        if int(s) > 2147483647:
            return 0
        if b:
            if (-1*int(s)) < -2147483648:
                return 0
            else:
                return (-1*int(s))
        
        return int(s)
        