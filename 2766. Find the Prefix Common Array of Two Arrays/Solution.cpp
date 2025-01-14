class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> x(51,0);
        vector<int> c;
        int count=0;

        for(int i=0;i<A.size();i++)
        {
            x[A[i]]++;
            x[B[i]]++;
            if(x[A[i]]==2 && x[B[i]]==2 && A[i]!=B[i])
            {
                count=count+2;
            }
            else if(x[A[i]]==2 || x[B[i]]==2)
            {
                count+=1;
            }
            c.push_back(count);
        }
        return c;
    }
};