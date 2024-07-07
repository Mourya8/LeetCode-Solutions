class Solution:
    def getEncryptedString(self, s: str, k: int) -> str:
        r = ""
        i = 0
        j = (k%len(s))
        while(i<len(s)):
            # print(i,j,s[j])
            r=r+s[j]
            if j==len(s)-1 :
                j=0
            else:
                j+=1
            i+=1
        return r

        