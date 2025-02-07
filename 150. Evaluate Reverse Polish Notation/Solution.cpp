class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto i: tokens)
        {
            if(i=="+" || i == "-" || i == "*" || i== "/")
            {
                if(s.size()>=2)
                {
                    int x = s.top();
                    s.pop();
                    int y = s.top();
                    s.pop();
                    if(i=="+") s.push(y+x);
                    if(i=="-") s.push(y-x);
                    if(i=="/") s.push(y/x);
                    if(i=="*") s.push(y*x);
                }
            }
            else
            {
                s.push(stoi(i));
            }
        }

        return s.top();
        
    }
};