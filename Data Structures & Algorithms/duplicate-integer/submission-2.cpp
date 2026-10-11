class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // revision version : 01
        unordered_set<int> hashset;
        int n = nums.size();

        for(int num : nums){
            if(hashset.contains(num)){
                return true;
            }
            hashset.insert(num);
        }
        return false;
    }
};