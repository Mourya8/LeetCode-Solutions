class Solution {
public:
    int numWaterBottles(int b, int e) {
        int count=b;
        int temp=0;
        int carry=0;
        while(b>=e)
        {
            carry=b%e;
            temp=b/e;
            count+=temp;
            b=temp+carry;
        }
        return count;
    }
};