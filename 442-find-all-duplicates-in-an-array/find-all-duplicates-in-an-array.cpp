class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int a=0,b=0;
        vector <int> r;
        int last=0;
        for(int i=0;i<nums.size();i++)
        {
            //cout << nums.size() <<" "<<nums[i]<<endl;
            if(abs(nums[i])!=nums.size())
            {
                if(nums[abs(nums[i])]<0)
                {
                    r.push_back(abs(nums[i]));
                }
                else{
                    nums[abs(nums[i])]=-1*nums[abs(nums[i])];
                }
            }
            else{
                last++;
            }
            // cout << i <<" "<<nums[i]<<endl;
            // cout<<last<<endl;
        }
        if(last==2)
        {
            r.push_back(nums.size());
        }
        return r;
    }
};