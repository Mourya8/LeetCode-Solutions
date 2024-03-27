class Solution:
    def minFlips(self, a: int, b: int, c: int) -> int:
        x = format(a, '032b')
        y = format(b, '032b')
        z = format(c, '032b')
        print(x," + ",y," + ",z)
        count = 0
        for i in range(len(z)-1,-1,-1):
            if x[i]=='1' and y[i]=='1' and z[i]=='0':
                count+=2
            elif x[i]=='1' and y[i]=='0' and z[i]=='0':
                count+=1
            elif x[i]=='0' and y[i]=='1' and z[i]=='0':
                count+=1
            elif x[i]=='0' and y[i]=='0' and z[i]=='1':
                count+=1
        
        return count