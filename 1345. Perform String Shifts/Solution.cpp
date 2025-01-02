class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int f=0;
        int d = 0;
        for(int i=0;i<shift.size();i++)
        {
            if(shift[i][0]==0) d=-1;
            if(shift[i][0]==1) d=1;

            f=f+(d*shift[i][1]);
        }
        if(f<0) f=(abs(f)%s.size())*(-1);
        else f=f%s.size();
        //cout<<f<<endl;
        if(f>0)
        {
            return s.substr(s.size()-f)+s.substr(0,s.size()-f);
        }
        else if(f<0)
        {
            return s.substr(-1*f)+s.substr(0,-1*f);
        }
        return s;
    }
};