class Solution {
public:
    int minimumCost(int m, int n, vector<int>& h, vector<int>& v) {
        sort(h.begin(),h.end());
        sort(v.begin(),v.end());
        int mincost=0;
        int total=1;
        int hp=1;
        int vp=1;
        int i=m-2,j=n-2;
        while(total!=m*n)
        {
            if(i>=0&&((j<0)||h[i]>=v[j]))
            {
                mincost+=(vp*h[i]);
                i--;
                hp++;
            }
            else if(j>=0&&(i<0||h[i]<=v[j]))
            {
                mincost+=(hp*v[j]);
                j--;
                vp++;
            }
            cout<<mincost<<" "<<total<<endl;
            total=hp*vp;
        }
        return mincost;
    }
};