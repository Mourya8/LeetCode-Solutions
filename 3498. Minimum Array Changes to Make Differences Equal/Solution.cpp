class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        map<int,int> m;
        int n=nums.size();
        for(int i=0;i<nums.size()/2;i++)
        {
            int a =abs(nums[i]-nums[n-1-i]);
            if(m.find(a)!=m.end()) m[a]++;
            else m[a]=1;
        }
        int diffCount = -1;
        vector<int> val;
        for(auto &it: m)
        {
            //cout<<it.first<<" "<<it.second<<endl;
            if(it.first<=k && it.second>diffCount)
            {
                val.push_back(it.first);
                diffCount = it.second;
            }
        }
        int minCount = INT_MAX;
        for (int j = 0; j < val.size(); j++){
        int count = 0;
        //cout<<diff<<endl;
        for(int i=0;i<nums.size()/2;i++)
        {
            int a =abs(nums[i]-nums[n-1-i]);
            if(a!=val[j])
            {
                //cout<<nums[i]-diff<<" "<<nums[n-1-i]-diff<<endl;
                // if(max(abs(nums[i]-0),abs(nums[i]-k)) >= diff || max(abs(nums[n-1-i]-0),abs(nums[n-1-i]-k)) >= diff)
                if (abs(k - nums[i]) >= val[j] || abs(0 - nums[i]) >= val[j] ||
                        abs(k - nums[n - i - 1]) >= val[j] ||
                        abs(0 - nums[n - i - 1]) >= val[j])
                {
                    count++;
                    //cout<<i<<endl;
                    //cout<<nums[i]<<" "<<nums[n-1-i]<<endl;
                }
                else 
                {
                    cout<<nums[i]<<" "<<nums[n-1-i]<<endl;
                    count+=2;
                }
            }
        }
        minCount=min(count,minCount);
        }
        return minCount;
    }
};
