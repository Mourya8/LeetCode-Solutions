class Solution {
public:
    bool isVowel(string s)
    {
        if(s[0]=='a'||s[0]=='e'||s[0]=='i'||s[0]=='o'||s[0]=='u')
        {

        }
        else
        {
            return 0;
        }
        if(s[s.size()-1]=='a'||s[s.size()-1]=='e'||s[s.size()-1]=='i'||s[s.size()-1]=='o'||s[s.size()-1]=='u')
        {

        }
        else
        {
            return 0;
        }
        return 1;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> dp(words.size(),0);
        if(isVowel(words[0])) dp[0]=1;
        for(int i=1;i<words.size();i++)
        {
            if(isVowel(words[i]))
            {
                dp[i]=dp[i-1]+1;
            }
            else
            {
                dp[i]=dp[i-1];
            }
            //cout<<dp[i]<<endl;
        }
        vector<int> r;
        for(int i=0;i<queries.size();i++)
        {
            if(queries[i][0]!=0)
            {
                r.push_back(dp[queries[i][1]]-dp[queries[i][0]-1]);
            }
            else
            {
                r.push_back(dp[queries[i][1]]);
            }
        }
        return r;
    }
};