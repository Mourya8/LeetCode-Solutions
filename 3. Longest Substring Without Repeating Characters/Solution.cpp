// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         if(s=="")
//         {
//             return 0;
//         }
//         int l=0;
//         int r=1;
//         map<char,int> m;
//         m[s[l]]=l;
//         int length=1;
//         int maxl=1;
//         while(r<s.size())
//         {
//             if(m.find(s[r])!=m.end())
//             {
//                 length=1;
//                 l=max(l,m[s[r]]+1);
//                // cout<<l<<" "<<s[r]<<endl;
//                 m.erase(m[s[l]]);
//                 m[s[l]]=l;
//             }
//                 m[s[r]]=r;
//                 length=r-l+1;
//                 //cout<<l<<" "<<r<<endl;
//                 maxl=max(maxl,length);
//                 r++;
//         }
//         return maxl;

//     }
// };
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> m;
        int l=0,r=0;
        int length=0;
        int n=s.size();
        while(r<n)
        {
            if(m.find(s[r])!=m.end())
            {
                l=max(l,m[s[r]]+1);
            }
            m[s[r]]=r;
            length=max(length,r-l+1);
            r++;
        }
        return length;
    }
};