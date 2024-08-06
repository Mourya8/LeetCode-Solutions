class Solution {
public:
    int minimumPushes(string word) {
        int minCount=0;
        vector<int> v(26,0);
        for(int i=0;i<word.size();i++)
        {
            v[word[i]-'a']++;
        }
       
        sort(v.begin(),v.end());
        int p=0;
        
        int i=25;
        while(i>=0)
        {
            p++;
            int n=8;
            while(n>0&&i>=0)
            {
                n--;
                //cout<<i<<" "<<p<<" "<<v[i]<<endl;
                minCount+=p*v[i];
                i--;
            }

        }
        return minCount;

    }
};