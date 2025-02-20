class Solution {
public:
    void helper(int n,string temp, string &r,int &k)
    {
        if(temp.size()==n)
        {
            k--;
            if(k==0) r = temp;
            return;
        }
        string s ="abc";
        for(int i=0;i<3;i++)
        {
            if(temp.size()>0)
            {
                if(temp[temp.size()-1]==s[i]) continue;
                else
                {
                    helper(n,temp+s[i],r,k);
                }
            }
            else{
                helper(n,temp+s[i],r,k);
            }
        }
        return;
    }

    string getHappyString(int n, int k) {
        int total = 3;
        for(int i=2;i<=n;i++)
        {
            total = total*2;
        }
        if(k>total) return "";
        string r="";
        helper(n,"",r,k);
        return r;
    }
};