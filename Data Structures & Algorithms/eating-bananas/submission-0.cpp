class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int result = right;

        while(left <= right){
            int k = left + (right - left)/2;

            long long hours = 0;

            for(int pile: piles){
                // Integer math trick for ceiling division: ceil(a / b) == (a + b - 1) / b
                 hours += (pile + k - 1)/ k ;
            }

            if(hours <= h){
                result = k;
                right = k - 1;
            } else {
                left = k + 1;
            }
        }

        return result;
    }
};
