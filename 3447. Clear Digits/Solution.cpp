class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        string temp="";
        for (int i=0;i<s.size();i++)
        {
            temp="";
            if(s[i]>='0'&&s[i]<='9')
            {
                while(!st.empty()&&(st.top()>='0'&&st.top()<='9'))
                {
                    temp=temp+st.top();
                    st.pop();
                }
                //cout<<temp<<endl;
                if(!st.empty())st.pop();
                for(auto x:temp)
                {
                    st.push(x);
                }
            }
            else
            {
                st.push(s[i]);
            }
        }
        temp="";
        while(!st.empty())
        {
            temp=st.top()+temp;
            st.pop();
        }
        return temp;
    }
};