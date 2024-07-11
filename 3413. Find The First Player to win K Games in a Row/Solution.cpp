class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        vector <int> wins(skills.size(),0);
        queue <pair<int,int>> q;
        int y=0;
        for(int i=0;i<skills.size();i++)
        {
            q.push(make_pair(skills[i],i));
            if(skills[y]<skills[i])y=i;
        }
        if(k>=skills.size()) return y;
        bool flag=1;
        while(flag)
        {
            auto temp=q.front();
            q.pop();
            if(temp.first>q.front().first)
            {
                wins[temp.second]++;
                if(wins[temp.second]==k)
                {
                    flag=0;
                    return temp.second;
                }
                int x=temp.first;
                temp.first=q.front().first;
                q.front().first=x;
                x=temp.second;
                temp.second=q.front().second;
                q.front().second=x;
                q.push(temp);
            }
            else
            {
                wins[q.front().second]++;
                if(wins[q.front().second]==k)
                {
                    flag=0;
                    return q.front().second;
                }
                q.push(temp);
            }

        }
        return 0;
    }
};