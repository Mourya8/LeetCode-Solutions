class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        if(s.size()==1)return 0;
        int i=0,j=1;
        int flag=0;
        int level = 0;
        do
        {
            i=0;j=1;
            int tempFlag=0;
            //cout<<s<<endl;
            while(j<s.size())
            {
                if(s[i]=='0'&&s[j]=='1')
                {
                    s[i]='1';
                    s[j]='0';
                    tempFlag=1;
                    i=i+2;j=j+2;
                }else
                {
                    i++;j++;
                }
                
            }
            flag=tempFlag;
            level++;
        }while(flag==1);
        return level-1;
    }
};