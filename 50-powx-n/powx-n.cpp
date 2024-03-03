class Solution {
public:
    double myPow(double x, int y) {
        double res=1.000000;
        int flag=0;
        // if(y<=INT_MIN&&x>1.000000)
        //     {
        //         return 0;
        //     }
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
        if(flag==1)
        {
            res=(double)(1.000000)/(double)res;
        }
        return res;
    }
};