class Solution {
public:
    int minOperations(vector<string>& logs) {
        int level=0;
        for (int i=0;i<logs.size();i++)
        {
            if(logs[i][0]=='.'&&logs[i][1]=='.')
            {
                if(level>0)level--;
            }
            else if(logs[i][0]=='.'&&logs[i][1]=='/')
            {
                continue;                
            }
            else
            {
                level++;
            }
        }
        return level;
    }
};