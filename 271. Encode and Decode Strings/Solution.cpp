class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string r="";
        for(int i=0;i<strs.size();i++)
        {
            r+=to_string(strs[i].size())+'.'+strs[i];
        }

        return r;
        
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> r;
        for(int i=0;i<s.size();i++)
        {
            string t="";
            while(s[i]!='.')
            {
                t+=s[i];
                i++;
            }
            int j=stoi(t);
            r.push_back(s.substr(i+1,j));
            i=i+j;
        }
        return r;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));