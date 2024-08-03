class Solution {
public:
    bool isPrime(int N) {
    if (N <= 1) {
        return false;
    }

    for (int i = 2; i <= N/2; i++) {
      
        if (N % i == 0) {
            return false;
        }
    }

    return true;
}
    int nonSpecialCount(int l, int r) {
        int total = r-l+1;
        int pd =0;
        int x =sqrt(l);
        int y= sqrt(r);
        for(int i=x;i<=y;i++)
        {
            int z = i*i;
            if(isPrime(i)&&(z)>=l&& z<=r)
            {
                cout<<i<<endl;
                pd++;
            }
        }
        return total-pd;
    }
};