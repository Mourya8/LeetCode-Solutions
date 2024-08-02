class Solution {
public:
    int countSeniors(vector<string>& details) {
        string temp="";
        int count =0;
        for(int i=0;i<details.size();i++ )
        {
            int t = stoi(details[i].substr(11, 2));
            if(t>60) count++;
            temp="";
        }
        return count;
    }
};