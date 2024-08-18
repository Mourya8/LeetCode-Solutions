class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int currentPrice = prices[0];
        for(int i=1;i<prices.size();i++)
        {
            int currentProfit = prices[i]-currentPrice;
            if(currentProfit>0)
            {
                profit +=currentProfit;
                currentPrice = prices[i];
            }
            else{
                currentPrice = min(currentPrice,prices[i]);
            }
        }
        return profit;
    }
};