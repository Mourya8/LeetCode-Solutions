class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> l(26,0);
        vector<int> r(26,0);
        for(int i=s.size()-1;i>0;i--)
        {
            r[s[i]-'a']++;
        }
        map <pair<int,int>, bool> m;
        l[s[0]-'a']++;
        //cout<<"x"<<endl;

        for(int i=1;i<s.size();i++)
        {
            r[s[i]-'a']--;
            for(int j=0;j<26;j++)
            {
                if(l[j]>0&&r[j]>0)
                {
                    //cout<<i<<" "<<j<<endl;
                    if(m.find({j,s[i]-'a'})==m.end())
                    {
                        m[{j,s[i]-'a'}]=1;
                    }
                }
            }
            l[s[i]-'a']++;
        }
        return m.size();
    }
};