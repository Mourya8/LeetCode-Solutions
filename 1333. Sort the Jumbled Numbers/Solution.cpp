class Solution {
public:
    static bool compare(pair <int,int> &a, pair<int,int> &b)
    {
        if(a.first==b.first) return a.second<b.second;
        return a.first<b.first;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector <pair<int,int>> v;
        for(int i=0;i<nums.size();i++)
        {
            string s = to_string(nums[i]);
            int temp = 0;
            for(int j=0;j<s.size();j++)
            {
                //cout<<s[i]<<" "<<mapping[s[i]-48]<<endl;
                temp= temp*10 + mapping[s[j]-'0'];
            }
            //cout<<temp<<endl;
            v.push_back(make_pair(temp,i));
        }
        sort(v.begin(),v.end(),compare);
        vector <int> r;
        for(int i=0;i<nums.size();i++)
        {
            r.push_back(nums[v[i].second]);
        }
        return r;
    }
};