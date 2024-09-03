class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum=0;
        for(int i=0;i<chalk.size();i++)
        {
            sum+=(long long)chalk[i];
        }
        k=k%sum;
        int j=0;
        while(k>=0)
        {
            for(int i=0;i<chalk.size();i++)
            {
                if(k>=chalk[i])
                {
                    k-=chalk[i];
                    j++;
                }
                else 
                {
                    return j%chalk.size();
                }
            }
        }
        return 1;
    }
};