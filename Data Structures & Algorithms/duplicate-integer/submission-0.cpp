class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
         unordered_set<int> hashset;
         int n = nums.size();

         for(int n : nums){
            if(hashset.contains(n)){
                return true;
            }
            hashset.insert(n);
         }
         return false;
    }
};