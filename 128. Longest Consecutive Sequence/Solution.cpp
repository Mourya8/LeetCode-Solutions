class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map < int,int> m;
        int maxLen = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(!m[nums[i]])
            {
                m[nums[i]]=m[nums[i]-1]+1+m[nums[i]+1];
                //cout<< nums[i] << " "<< m[nums[i]]<< " || " << nums[i]-1 << " "<< m[nums[i]-1]<< " || " << nums[i]+1 << " "<< m[nums[i]+1]<< endl;
                m[nums[i]-m[nums[i]-1]]=m[nums[i]];
                m[nums[i]+m[nums[i]+1]]=m[nums[i]];
                maxLen = max(maxLen,m[nums[i]]);
            }

        }
        return maxLen;
    }
};