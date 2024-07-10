class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int minColor=INT_MAX;
        int tempWhite=0;
        int j=0;
        for(j=0;j<k;j++)
        {
            if (blocks[j]=='W')tempWhite++;
        }
        //cout<<j<<" "<<tempWhite<<endl;
        int i=0;
        minColor=min(minColor,tempWhite);
        while(j<blocks.size())
        {
            
            if(j<blocks.size())
            {
                if(blocks[i]=='W')tempWhite--;
                if(blocks[j]=='W')tempWhite++;
                minColor=min(minColor,tempWhite);
            }
            i++;j++;
            //cout<<j<<" "<<tempWhite<<endl;
        }
        return minColor;
    }
};