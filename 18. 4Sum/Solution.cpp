class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> r;
        map<vector<int>,int> m;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n==0)
            return r;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                long t = long(target)-long(nums[i])-long(nums[j]);
                int front=j+1;
                int en=n-1;
                while(front<en)
                {
                    if(long(nums[front]+nums[en])>t)
                    {
                        en--;
                    }
                    else if(long(nums[front]+nums[en])<t)
                    {
                        front++;
                    }
                    else 
                    {
                        vector<int> v(4,0);
                        v[0]=nums[i];
                        v[1]=nums[j];
                        v[2]=nums[front];
                        v[3]=nums[en];
                        if(m.find(v)==m.end())
                        {
                            r.push_back(v);
                            m[v]=1;
                        }
                        front++;
                        en--;
                    }
                }
            }
        }
        return r;
    }
};