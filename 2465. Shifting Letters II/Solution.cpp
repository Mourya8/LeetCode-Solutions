class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        // for(int i=0;i<shifts.size();i++)
        // {
        //     int t;
        //     if (shifts[i][2]==1)t=1;
        //     else t=-1;
        //     for(int j=shifts[i][0];j<=shifts[i][1];j++)
        //     {
        //         if(s[j]=='a'&&t==-1)s[j]='z';
        //         else if(s[j]=='z' && t==1) s[j]='a';
        //         else s[j]+=t;
        //     }
        // }
        //return s;

        vector<int> d(s.size()+1,0);
        for(auto x: shifts){
            
            if(x[2]==0){
                d[x[0]]--;;
                d[x[1]+1]++;
            }
            else{
                d[x[0]]++;;
                d[x[1]+1]--;
            }            
        }
        for(int i=1;i<d.size();i++)
        {
            d[i]+=d[i-1];
        }
        for(int j=0;j<s.size();j++)
        {
            cout<<d[j]<<endl;
            int t=(d[j]+s[j]-'a')%26;
            if(t<0)t=t+26;
            cout<<t<<" t"<<endl;
            s[j]='a'+t;
        }
        return s;
    }
};