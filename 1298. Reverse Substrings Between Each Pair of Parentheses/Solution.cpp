class Solution {
public:
    string reverseParentheses(string s) {
        //string ret="";
        stack <char> st;
        for (int i=0;i<s.size();i++)
        {
            if(s[i]==')')
            {
                string temp="";
                while(st.top()!='(')
                {
                    temp+=st.top();
                    st.pop();
                }
                //cout<<temp<<endl;
                if(st.top()=='(')
                {
                    st.pop();
                }
                for(int j=0;j<temp.size();j++)
                {
                    st.push(temp[j]);
                }
            }
            else
            {
                st.push(s[i]);
            }
        }
        s="";
        while(!st.empty())
        {
            s= st.top()+s;
            st.pop();
        }
        return s;
    }
};