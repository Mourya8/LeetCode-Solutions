class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int i=0;
        for(i=0;i<names.size();i++)
        {
            int maxIndex = i;
            for(int j=i;j<names.size();j++)
            {
                if(heights[j]>heights[maxIndex])
                {
                    maxIndex=j;
                }
            }
            //cout<<heights[i]<<" "<<heights[maxIndex]<<endl;
            int temp = heights[maxIndex];
            heights[maxIndex]=heights[i];
            heights[i]=temp;
            //cout<<heights[i]<<" "<<heights[maxIndex]<<endl;
            string t = names[maxIndex];
            names[maxIndex]=names[i];
            names[i]=t;
        }
        return names;
    }
};