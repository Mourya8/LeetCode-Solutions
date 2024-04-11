class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0 && m.find(nums[i])==m.end())
                m[nums[i]]=i;
        }
         auto start = m.begin();
         if(start->first!=1)
         {
            return 1;
         }
    auto end = m.begin();

    // Move the 'end' iterator ahead by 2 positions
    std::advance(end, 1);

    // Iterate from start to end using two pointers
    while (end != m.end()) {
        if (start->first+1!=end->first)
        {
            return start->first+1;
        }
        ++start;
        ++end;
    }

    return m.size()+1;
    }
};