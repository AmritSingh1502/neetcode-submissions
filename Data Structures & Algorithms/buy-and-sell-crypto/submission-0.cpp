class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // buy low , sell high
         int left = 0; // buying
         int right = 1; // selling

         int maxProfit = 0;

         while(right < prices.size()){
            //profitable ?
            if(prices[left] < prices[right]){
                int profit = prices[right] - prices[left];
                maxProfit = max(maxProfit, profit);
            } else {
                left = right;
            }
            right += 1;
         }
    return maxProfit;

    }
};
