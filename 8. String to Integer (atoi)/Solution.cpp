class Solution {
public:
    int myAtoi(string s) {
        int r=0;
        bool spaceFound=0;
        long tenPower=1;
        if(s=="-2147483647")
        {
            return INT_MIN+1;
        }
        for(int i=s.size()-1;i>=0;i--)
        {
            if((s[i]=='-'||s[i]=='+')&&(s[i+1]>=48&&s[i+1]<=57))
            {
                if(s[i]=='-')
                {
                if(r==INT_MAX)
                {
                    r=INT_MIN;
                }
                else if(r==INT_MIN)
                {
                    r=INT_MAX;
                }  
                else{    
                    r=r*(-1);
                }
                }
            }
            else if(r!=0&&(s[i]>57||s[i]<48))
            {
                if(s[i]!=' ')
                {
                    r=0;
                    tenPower=1;
                }
                else{
                    spaceFound=1;
                }
            }
            else if(s[i]>=48&&s[i]<=57)
            {
                if(i+1<=s.size()-1)
                {
                    if(s[i+1]<48||s[i+1]>57)
                    {
                        r=0;
                        tenPower=1;
                    }
                }
                long temp=(long)r+(long)(s[i]-48)*tenPower;
                if(temp>INT_MAX)
                {
                    r=INT_MAX;
                }
                else if(temp<INT_MIN)
                {
                    r=INT_MIN;
                }
                else
                {
                r=r+(s[i]-48)*((int)tenPower);
                if(tenPower<1000000000000000000)
                {
                    tenPower=tenPower*10;

                }
                }
            }

        }
        return r;
    }
};