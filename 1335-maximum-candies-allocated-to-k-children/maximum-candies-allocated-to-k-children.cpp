class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long s=0;
        for (int i=0;i<candies.size();i++)
        {
            s+=(long long)candies[i];
        }
        if (k>s) return 0;
        sort(candies.begin(),candies.end());
        long long left=0;
        long long right=s;
        
        while(left<right)
        {
            s=0;
            long long mid = (long long)((right+left+1)/2);
            cout <<mid<<endl;
            for(auto& i: candies )
            {
                s+=i/mid;
            }
            if(s>=k) left=mid;
            else{
                right = mid-1;
            }
        }
        return left;

    }
};