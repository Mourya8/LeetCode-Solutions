class Solution {
public:
    string minWindow(string str, string t) {
        if(str.size() ==0) return "";
    unordered_map <char, int> m;
    int l=0; 
    int r=0;
    unordered_map <char,int> a;
    for(int i=0;i< t.size();i++)
    {
        if(a.find(t[i])!=a.end()) a[t[i]]++;
        else a[t[i]]=1;
    }
    string retStr="";
    int start=0,minLength=0;
    while(l<str.size())
    {
        bool x=1;
        for(auto &it: a)
        {
            if(m.find(it.first)!=m.end())
            {
                //cout<< m[it.first]<<" "<<it.second<<endl;
                if(m[it.first]<it.second) 
                {
                    
                    x=0;
                    break;
                }
            }
            else
            {
                x=0;
                break;
            }
        }
        if(x)
        {
            //cout<<str.substr(l,r-l)<<" test"<<endl;
            if(retStr=="") 
            {
                retStr=str.substr(l,r-l);
                start=l; minLength=r-l;
            }
            else{
                if(r-l<minLength)
                {
                    start=l; minLength=r-l;
                }
            }
            m[str[l]]--;
            l++;
        }
        else{
            if(r>=str.size()) break;
            if(m.find(str[r])!=m.end())
            {
                m[str[r]]++;
            }
            else
            {
                m[str[r]]=1;
            }
            r++;
        }
    }
    return str.substr(start,minLength);
    }
};