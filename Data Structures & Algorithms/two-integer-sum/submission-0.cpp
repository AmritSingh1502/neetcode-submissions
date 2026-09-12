class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp; //val to index

        for( int i = 0; i<nums.size(); i++){
            int complement = target - nums[i];

            if(mpp.contains(complement)){
                return{mpp[complement],i};
            }

            mpp[nums[i]] = i;
        }

        return {};
    }
};
