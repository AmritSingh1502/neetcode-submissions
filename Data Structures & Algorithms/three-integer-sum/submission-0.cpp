class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> result;
        // sort the array to handle duplicates 
        sort(nums.begin(), nums.end());

        for( int i =0 ; i< nums.size(); i++){
            if(nums[i] > 0) break;

            // skip duplicates value for the first element
            if(i > 0 && nums[i] == nums[i  - 1]) continue;

            int left = i + 1;
             int right = nums.size() -1 ;

             while(left  < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if(sum > 0){
                    right--;
                } else if(sum < 0){
                    left++;
                } else {
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    // right--;

                    while(left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                }
    
             }
        }
        return result;

        // time compx : O(n^2)
        // space compx : O(n) || O(1) based on sorting algo
    }
};
