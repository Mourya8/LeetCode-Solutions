class Solution {
public:
    int reverse(int x) {
        long l= long(INT_MAX);
        string s=to_string(x);
        int i=0,j=s.size()-1;

        while(i<j)
        {
            swap(s[i],s[j]);
            i++;
            j--;
        }

        //cout <<s<<endl;

        long t= stol(s);

        if(s[s.size()-1]=='-')
        {
            t=t*(-1);
        }

        if (l<t || long(INT_MIN)>t)
            return 0;
        
        return int(t);
    }
};