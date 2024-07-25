class Solution {

    int Partition_Hoare(vector<int>& A,int l, int h)
    {
        int x=A[l], i=l-1, j=h+1;

        while(1)
        {
            do{i++;} while(A[i]<x);
            do{j--;} while(A[j]>x);

            if(i>=j)return j;
            swap(A[i],A[j]);
        }
    }

    void Quick_Sort(vector<int>& A,int l,int h)
    {
        if(l<h)
        {
            swap(A[l],A[rand()%(h-l+1)+l]);
            int m = Partition_Hoare(A,l,h);
            Quick_Sort(A,l,m);
            Quick_Sort(A,m+1,h);
        }
    }

public:
    vector<int> sortArray(vector<int>& A) {
        Quick_Sort(A,0,A.size()-1);
        return A;
    }
};