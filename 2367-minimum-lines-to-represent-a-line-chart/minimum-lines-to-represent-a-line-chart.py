class Solution:
#     def inCurrentLine(a: List[int],b: List[int],l:List[int])-> bool:
#         if (b[0]-a[0])==0:
#             y = 1e9
#         else:
#             y = float(float(b[1]-a[1])//float(b[0]-a[0]))
#         x = float(l[1])-(y*float(l[0]-b[0]))-float(b[1])
#         return True if float(x)==float(0) else False

#     def minimumLines(self, stockPrices: List[List[int]]) -> int:
#         if len(stockPrices)==1:
#             return 0
#         count = 1
#         stockPrices.sort()
#         current=stockPrices[0]
#         for i in range(1,len(stockPrices)-1):
#             if Solution.inCurrentLine(current,stockPrices[i],stockPrices[i+1]):
#                 continue
#             else:
#                 count+=1
#                 current =stockPrices[i]
        
#         return count
    def minimumLines(self, A) -> int:
        A.sort()
        ans = len(A) - 1
        for i in range(2, len(A)):
            if (A[i][1] - A[i-1][1]) * (A[i-1][0] -A[i-2][0]) == (A[i][0] - A[i-1][0]) * (A[i-1][1] - A[i-2][1]): 
                ans -= 1
        return ans