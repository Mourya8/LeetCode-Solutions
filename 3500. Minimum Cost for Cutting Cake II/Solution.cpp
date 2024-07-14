class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& h, vector<int>& v) {
        sort(h.begin(),h.end());
        sort(v.begin(),v.end());
        long long mincost=0;
        int total=1;
        int hp=1;
        int vp=1;
        int i=m-2,j=n-2;
        while(m!=hp||n!=vp)
        {
            if(i>=0&&((j<0)||h[i]>=v[j]))
            {
                mincost+=(long)((long)vp*(long)h[i]);
                i--;
                hp++;
            }
            else if(j>=0&&(i<0||h[i]<=v[j]))
            {
                mincost+=(long)((long)hp*(long)v[j]);
                j--;
                vp++;
            }
        }
        return mincost;
    }
};