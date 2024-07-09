class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        vector <int> r;
        for(int i=0;i<asteroids.size();i++)
        {
            if(s.empty())
            {
                s.push(asteroids[i]);
            }
            else
            {
                int remain = asteroids[i];
                if(s.top()>0&&remain<0)
                {
                    while(!s.empty()&&(s.top()>0&&remain<0)){
                        //cout<<s.top()<<" "<<remain<<endl;
                        int temp = s.top();
                        s.pop();

                        if(remain+temp==0)
                        {
                            remain = 0;
                        }
                        else if(abs(remain)<abs(temp))
                        {
                            remain = temp;
                        }
                    }
                    if(remain!=0)s.push(remain);
                }
                else
                {
                    s.push(remain);
                }

            }
        }
        while(!s.empty())
        {
            int temp=s.top();
            s.pop();
            r.push_back(temp);
        }
        reverse(r.begin(), r.end());
        return r;
    }
};