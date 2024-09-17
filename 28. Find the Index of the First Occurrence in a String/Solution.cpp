class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=needle.size();
        if(haystack.size()<n)
        {
            return -1;
        }
        vector<int> r;

        for(int i=0;i<=haystack.size()-n;i++)
        {
            cout<<i<<endl;
            if(haystack[i]==needle[0])
            {
                if(haystack.substr(i,n)==needle)
                {
                    return i;
                }
            }
        }

        return -1;
    }
};