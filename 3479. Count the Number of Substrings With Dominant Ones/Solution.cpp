// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         vector<int> v(s.size(),0);
//         int count=0;
//         if(s[0]=='1') v[0]=1;
//         for(int i=1;i<s.size();i++)
//         {
//             if(s[i]=='1') v[i]=v[i-1]+1;
//             else v[i]=v[i-1];
//         }
//         count=count+v[s.size()-1];
//         int l,r,temp,t;
//         for(int i=2;i<=s.size();i++)
//         {
//             l=0;
//             r=i-1;
//             while(r<s.size())
//             {
//                 temp=v[r]-v[l];
//                 if(s[l]=='1') temp++;
//                 t=(i-temp);
//                 if(temp>=t*t) 
//                 {
                    
//                     count++;
//                 }
//                 // else
//                 // {
//                 //     cout<<temp<<" "<<i<<" "<<l<<" "<<r<<endl;
//                 // }
//                 l++;
//                 r++;
//             }
//         }
//         return count;
//     }
// };
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int pre[n];
        for(int i=0;i<n;i++)pre[i] = (i>0?pre[i-1]:0)+(s[i]-'0');
        int next_zero[n];
        int prev = n;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='0')
            {
                prev = i;
                continue;
            }
            next_zero[i] = prev;
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            int j = i;
            while(j<n){
                int o = pre[j]-pre[i]+(s[i]-'0');
                int t = o - (j-i+1-o)*(j-i+1-o);
                if(t>=0)
                {
                    if(s[j]=='1')
                    {
                        int k = next_zero[j];
                        ans+=(k-j);
                        j = k;
                    }
                    else
                    {
                        ans++;
                        j++;
                    }
                }
                else
                {
                    if(n-j<abs(t))break;
                    j++;
                }
            }
        }
        return ans;
    }
};