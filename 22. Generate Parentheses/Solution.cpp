class Solution {
public:
    void helper(vector<string> &r,string st, stack <char> s, int n)
    {
        if(s.empty()&& n ==0)
        {
            r.push_back(st);
            return;
        }
        if(n>0) 
        {
            s.push(')');
            helper(r,st+'(',s,n-1);
            s.pop();
        }
        if(!s.empty())
        {
            s.pop();
            helper(r,st+')',s,n);
        }
        return;
    }
    
    vector<string> generateParenthesis(int n) {
        // write your code here
        vector<string> r;
        string st;
        stack <char> s;
        helper(r,st,s,n);
        return r;
    }
    // vector<string> generateParenthesis(int n) {
        
    // }
};