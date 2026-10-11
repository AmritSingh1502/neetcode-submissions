class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // revison version : 01
        unordered_map<int,int> mp;

        for( int i =0 ; i< nums.size(); i++){
            int comp = target - nums[i];

            if(mp.contains(comp)){
                return {mp[comp], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};
