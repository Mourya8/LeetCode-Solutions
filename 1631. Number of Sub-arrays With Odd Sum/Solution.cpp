class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int even = 0;
        int mod = 1000000007;
        int odd =0;
        int sum =0;
        int count = 0;
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
            if(sum%2==1)
            {
                odd++;
                count = count + (even)+1;
                count = count % mod;
            }
            else
            {
                even++;
                count = count + ( odd);
                count = count % mod;
            }
        }

        return count%mod;
    }
};