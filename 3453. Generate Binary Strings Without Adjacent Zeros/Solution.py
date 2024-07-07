class Solution:
    def validStrings(self, n: int) -> List[str]:
        def dfs(s,d, n,l):
            if len(s)==n:
                if s not in d:
                    l.append(s)
                    d[s]=1
                return
            if s[len(s)-1]=='0':
                s=s+'1'
                dfs(s,d,n,l)
            else:
                dfs(s+'0',d,n,l)
                dfs(s+'1',d,n,l)
        
        s=""
        d={}
        l=[]
        dfs(s+'0',d,n,l)
        dfs(s+'1',d,n,l)
        return l
