class Solution {
public:
    int maxScore(string s) {
        if(s=="00"||s=="11")
        {
            return 1;
        }
        if(s=="01")
        {
            return 2;
        }
        int n=s.size();
        vector<int> a(n,0);
        vector <int> b(n,0);
        if(s[0]=='0')
        {
            a[0]=1;
        }
        if(s[n-1]=='1')
        {
            b[n-1]=1;
        }
        cout<<b[n-1]<<endl;
        for(int i=1;i<n;i++)
        {
            if(s[i]=='0')
            {
                a[i]=a[i-1]+1;
            }
            else{
                a[i]=a[i-1];
            }
            if(s[n-1-i]=='1')
            {
                b[n-1-i]=b[n-i]+1;
            }
            else{
                b[n-1-i]=b[n-i];
            }
            //cout<<a[i]<<" "<<b[n-1-i]<<endl;
        }
        // for(int i=0;i<n;i++)
        // {
        // }
        int maxSum=0;
        for(int i=1;i<n-1;i++)
        {
            maxSum=max(maxSum,a[i]+b[i]);
        }
        return maxSum;
    }
};