class Solution {
public:
    void helper(int n,string temp, vector <string> &v)
    {
        if(temp.size()==n)
        {
            v.push_back(temp);
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
                    helper(n,temp+s[i],v);
                }
            }
            else{
                helper(n,temp+s[i],v);
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
        vector<string> v;
        helper(n,"",v);
        sort(v.begin(),v.end());
        return v[k-1];
    }
};