class Solution {
public:
    string transform(string t)
    {
        int sum=0;
        for(int i=0;i<t.size();i++)
        {
            sum+=(t[i]-'0');
        }

        return to_string(sum);
    }

    int getLucky(string s, int k) {
        string t="";
        for(int i=0;i<s.size();i++)
        {
            t=t+to_string((s[i]-'a')+1);
        }
        for(int i=0;i<k;i++)
        {
            t=transform(t);
        }

        return stoi(t);
    }
};