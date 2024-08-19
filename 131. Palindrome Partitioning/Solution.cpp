class Solution {
public:
    bool isPalindrome(string s)
    {
        int l=0;
        int r=s.size()-1;
        while(l<r)
        {
            if(s[l]!=s[r]) return 0;
            l++;
            r--;
        }
        return 1;
    }

    int n;
    vector<vector<string>> partition(string s) {
        n=s.size();
        vector<vector<string>> res;
        vector<string> curr;
        backTrack(s,0,1,curr,res);
        return res;
    }

    void backTrack(string& s, int beg, int len, vector<string> curr, vector<vector<string>>& res) {
        if(beg==n) {
            res.push_back(curr);
            return;
        }
        if((beg+len)>n)return;


        backTrack(s,beg,len+1,curr,res);

        if(isPalindrome(s.substr(beg, len))) {
            curr.push_back(s.substr(beg, len));
            backTrack(s, beg+len, 1, curr, res);
        }
    }
};