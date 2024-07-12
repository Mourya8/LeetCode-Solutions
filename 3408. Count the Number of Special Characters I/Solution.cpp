class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<char,int> m;
        int count =0;
        vector<bool> c(27,0);
        int diff = 'a'-'A';
        for(int i=0;i<word.size();i++)
        {
            if(word[i]>='a'&&word[i]<='z')
            {
                if(m.find(word[i]-diff)!=m.end())
                {
                    if(!c[word[i]-'a'])
                    {
                        count++;
                        c[word[i]-'a']=1;
                    }
                    m.erase(word[i]-diff);
                }
                else
                {
                    m[word[i]]=1;
                }
            }
            else
            {
                if(m.find(word[i]+diff)!=m.end())
                {
                    if(!c[word[i]-'A'])
                    {
                        count++;
                        c[word[i]-'A']=1;
                    }
                    m.erase(word[i]+diff);
                }
                else
                {
                    m[word[i]]=1;
                }
            }
        }
        return count;
    }
};