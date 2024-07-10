class Solution {
public:
    string predictPartyVictory(string senate) {
        //return "Dire";
        queue <char> q;
        int rad=0;
        int dire=0;
        int rd=0;
        int rr=0;
        for (int i=0;i<senate.size();i++)
        {
            q.push(senate[i]);
            if(senate[i]=='R')rad++;
            else dire++;
        }
        char t='a';
        while(!q.empty()&&rad>0 && dire >0)
        {
            char temp= q.front();
            //cout<<t<<" "<<rr<<" "<<rd<<endl;
            q.pop();
            if (rr<0)
            {
                if(temp=='R')
                {
                    rr--;
                    q.push(temp);
                }
                else
                {
                    dire--;
                    rr++;
                    t='a';
                }
            }
            else if(rd<0)
            {
                if(temp=='D')
                {
                    rd--;
                    q.push(temp);
                }
                else
                {
                    rad--;
                    rd++;
                    t='a';
                }
            }
            else
            {
                if(temp=='R')rr--;
                else rd--;
                t=temp;
                q.push(temp);
            }

        }
        if (rad>0) return "Radiant";
        else return "Dire";
    }
};