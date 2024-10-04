class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_map<string,bool> m;
        for(int i=0;i<bannedWords.size();i++)
        {
            m[bannedWords[i]]=1;
        }

        int count =0;
        for(int i=0;i<message.size();i++)
        {
            if(m.find(message[i])!=m.end())
            {
                count++;
                if(count==2) return 1;
            }
        }

        return 0;

    }
};