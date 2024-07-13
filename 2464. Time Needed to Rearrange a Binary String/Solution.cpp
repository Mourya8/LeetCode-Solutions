class Solution {
public:
    int secondsToRemoveOccurrences(string s) {

        int n=s.length();
        int flag=1;
        int cc=0;
        while(1){
            flag=1;
            for(int i=0;i<n-1;i++)
            {
                if(s[i]=='0' && s[i+1]=='1'){
                    s[i]='1';
                    s[i+1]='0';
                    i++;
                    flag=0;

                }

            }
            
            if(flag==1){
                break;
            }
            cc++;
        }
        return cc;
            
    }
};