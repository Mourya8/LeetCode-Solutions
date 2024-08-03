class Solution {
public:
//     bool isPrime(int N) {
//     if (N <= 1) {
//         return false;
//     }

//     for (int i = 2; i <= N/2; i++) {
      
//         if (N % i == 0) {
//             return false;
//         }
//     }

//     return true;
// }
    int nonSpecialCount(int l, int r) {
        int total = r-l+1;
        int pd =0;
        int x =sqrt(l);
        int y= sqrt(r);
        int limit = (int)(sqrt(r));
        vector<bool> v(limit+1, true);
        v[0] = v[1] = false;

        for (int i=2; i*i<=limit; i++) {
            if (v[i]) {
                for (int j=i*i; j<=limit; j+=i) {
                    v[j] = false;
                }
            }
        }
        for(int i=x;i<=y;i++)
        {
            int z = i*i;
            if(v[i]&&(z)>=l&& z<=r)
            {
                cout<<i<<endl;
                pd++;
            }
        }
        return total-pd;
    }
};