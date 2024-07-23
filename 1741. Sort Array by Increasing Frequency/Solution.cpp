class Solution {

    private:
    static bool comparePairs(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first) {
        return a.second > b.second; 
    }
    return a.first < b.first; 
}
public:
    

    vector<int> frequencySort(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector <pair<int,int>> p;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i+1!=nums.size()&&nums[i]!=nums[i+1])
            {
                //cout<<nums[i]<<endl;
                count++;
                p.push_back(make_pair(count,nums[i]));
                count = 0;
            }
            else
            {
                count++;
            }
        }
        //cout<<nums[nums.size()-1]<<endl;
        p.push_back(make_pair(count,nums[nums.size()-1]));
        sort(p.begin(),p.end(),comparePairs);
        vector <int> r;
        for(auto it: p)
        {
            //cout<<it.first<<endl;
            for(int j=0;j<it.first;j++)
            {
                r.push_back(it.second);
            }
        }
        return r;
    }
};