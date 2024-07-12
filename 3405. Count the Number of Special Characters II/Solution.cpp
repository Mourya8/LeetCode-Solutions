class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<char,int> m;
        int count =0;
        vector<int> c(27,0);
        int diff = 'a'-'A';
        for(int i=0;i<word.size();i++)
        {
            if(word[i]>='a'&&word[i]<='z')
            {
                //cout<<word[i]<<endl;
                if(c[word[i]-'a']==1)
                {
                    c[word[i]-'a']=-1;
                }
                else if(c[word[i]-'a']==0){
                    //cout<<word[i]<<endl;
                    m[word[i]]=1;
                }
            }
            else
            {
                //cout<<word[i]<<endl;
                if(m.find(word[i]+diff)!=m.end())
                {
                    
                    if(c[word[i]-'A']==0)
                    {
                        c[word[i]-'A']=1;
                    }
                }
                else
                {
                    //m[word[i]]=1;
                    c[word[i]-'A']=-1;
                }
            }
        }
        for(int i=0;i<c.size();i++)
        {
            if(c[i]==1)
            {
                count+=c[i];
                //cout<<i<<endl;
            }
        }
        return count;
    }
};