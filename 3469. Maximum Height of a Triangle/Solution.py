class Solution:
    def maxHeightOfTriangle(self, red: int, blue: int) -> int:
        if red > blue:
            red, blue = blue, red

        # number of odd rows
        odd = isqrt(red)
        # sum of even rows when number of odd rows == number of even rows
        even_sum = odd ** 2 + odd
        
        # even rows are red, odd rows are blue
        if even_sum <= red and even_sum + odd + 1 <= blue:
            return odd * 2 + 1
        
        # odd rows are red, even rows are blue
        if even_sum <= blue:
            return odd * 2
        
        # odd rows are red but there is 1 less odd row, even rows are blue
        return odd * 2 - 1