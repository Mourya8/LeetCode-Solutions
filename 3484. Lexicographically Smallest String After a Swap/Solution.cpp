class Solution {
public:
    string getSmallestString(string s) {

        for(int i=0;i<s.size()-1;i++)
        {
            int temp1=s[i]-'0';
            int temp2=s[i+1]-'0';
            //cout<<temp1<<" "<<temp2<<endl;
            if((temp1%2==0&&temp2%2==0)||(temp1%2==1&&temp2%2==1))
            {
                if(temp1>temp2)
                {
                    char t = s[i];
                    s[i]=s[i+1];
                    s[i+1]=t;
                    break;
                }
            }

        }
        return s;
    }
};