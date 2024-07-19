class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()) return 0;
        vector <int> a(26,0);
        vector <int> b(26,0);
        vector<bool> presentOne(26,false);
        vector<bool> presentTwo(26,false);
        for( int i=0;i<word1.size();i++)
        {
            a[word1[i]-'a']++;
            presentOne[word1[i]-'a'] = true;
            b[word2[i]-'a']++;
            presentTwo[word2[i]-'a'] = true;
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        if(a==b && presentOne == presentTwo)
        {
            return 1;
        }
        return 0;
    }
};