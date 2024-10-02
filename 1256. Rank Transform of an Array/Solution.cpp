class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map <int,vector<int>> m;
        vector <int> r(arr.size(),0);

        for(int i=0;i<arr.size();i++)
        {
            m[arr[i]].push_back(i);
        }
        int count = 1;

        for(const auto& itr : m)
        {
            vector <int> temp = itr.second;
            for(int j=0;j<temp.size();j++)
            {
                r[temp[j]]=count;
            }
            count++;
        }

        return r;
    }
};