class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> m;
        map<int, bool> p;
        for( int i=0;i<arr.size();i++)
        {
            if(m.find(arr[i])!=m.end())
            {
                m[arr[i]]++;
            }
            else
            {
                m[arr[i]]=1;
            }
        }
        for( auto &it:m)
        {
            if(p.find(it.second)!=p.end())
            {
                return false;
            }
            else p[it.second]=1;
        }
        return 1;
    }
};