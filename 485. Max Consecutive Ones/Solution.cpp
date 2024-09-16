class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& num) {
        int maxc=0;
        int count=0;
        int n=num.size();
        for(int i=0;i<n;i++)
        {
            while(i<n && num[i]==1  )
            {
                cout<<i<<endl;
                count++;
                i++;
            }
            //cout<<"a"<<endl;
            maxc=max(maxc,count);
            //cout<<maxc<<endl;
            count=0;
        }
        return maxc;
    }
};