class Solution {
public:
    void rotate(int l, int r, string &s)
    {
        while(l<r)
        {
            if(s[l]!='('&&s[l]!=')'&&s[r]!=')'&&s[r]!='(')
            {
                char temp=s[l];
                s[l]=s[r];
                s[r]=temp;
                l++;
                r--;
            }
            else if((s[l]=='('||s[l]==')')&&s[r]!=')'&&s[r]!='(')l++;
            else if(s[l]!='('&&s[l]!=')'&&(s[r]!=')'||s[r]!='('))r--;
            else 
            {
                l++;
                r--;
            }
        }
        cout<<s<<endl;
    }
    string reverseParentheses(string s) {
        string ret="";
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
        while(!st.empty())
        {
            ret= st.top()+ret;
            st.pop();
        }
        return ret;
    }
};