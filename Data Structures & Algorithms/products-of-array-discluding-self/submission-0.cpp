class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*
            first i can think of a solution like we can keep 2 list
            prefix O(n) and postfix 0(n) and then product of prefix and postfix will give the   required ans
            for each element.
            but here we are using extra space for prefix and postfix
            so need to optimize using save in directly in output array

        */
        int n = nums.size();
        vector<int>ans(n,1);

        // calcuate the prefix products
         int leftProducts = 1;

         for( int i = 0 ; i<n  ; ++i){
            ans[i] = leftProducts;
            leftProducts *= nums[i];
         }

         // calculate the postfix product
         int rightProducts = 1;
         for( int i = n - 1; i>= 0 ; --i){
            ans[i] *= rightProducts;
            rightProducts *= nums[i];
         }

         return ans;

         // time compexity : O(n)
         // space complexity : O(1)
    }
};
