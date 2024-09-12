class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<=1) return s.size();
        int maxL = INT_MIN;
        map<char,int> x;
        int l=0;
        int r = 0;
        while(r<s.size())
        {
            if(x.find(s[r])==x.end())
            {
                
                x[s[r]]=r;
            }
            else
            {
                
                l=max(l,x[s[r]]+1);
                x[s[r]]=r;
                
            }
            //cout<<l<<" "<<r<<endl;
            maxL = max(maxL,r-l+1);
            r++;
        }
        //cout<<l<<" "<<r<<endl;
        maxL = max(maxL,r-l);
        return maxL;
    }
};