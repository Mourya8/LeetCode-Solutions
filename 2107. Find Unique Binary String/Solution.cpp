class Solution {
public:
    void solve(set<string> &s, string temp, string &r,int &n)
    {
        if(n==temp.size())
        {
            if(s.find(temp)==s.end()) r = temp;
            return;
        }
        string t = "01";
        for(int i=0;i<2;i++)
        {
            solve(s,temp+t[i],r,n);
        }
        return;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        set<string> s;
        s.insert(nums.begin(),nums.end());
        string r = "";
        int n=nums.size();
        solve(s,"",r,n);
        return r;
    }
};