class Solution {
public:
    double myPow(double x, int y) {
        double res=1.000000;
        bool flag=0;
        if(y<0)
        {
            flag=1;
            y=abs(y);

        }
        while(y>0)
        {
            if(y%2==1)
            {
                res=res*x;
                y--;
            }
            y=y/2;
            x=x*x;
        }
        if(flag)
        {
            res=(double)(1.000000)/(double)res;
        }
        return res;
    }
};