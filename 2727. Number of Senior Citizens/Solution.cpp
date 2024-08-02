class Solution {
public:
    int countSeniors(vector<string>& details) {
        string temp="";
        int count =0;
        for(int i=0;i<details.size();i++ )
        {
            temp=temp+details[i][11]+details[i][12];
            //cout<<temp<<endl;
            int t = stoi(temp);
            if(t>60) count++;
            temp="";
        }
        return count;
    }
};