class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // by sorting we can solve this but timne complx will be O(nlogn)

        // insert all the numbers into a hash set for O(1) lookup
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for( int num : nums){
            // check if 'num' is the start of a sequence
            if(numSet.find(num -1) == numSet.end()){
                int currentNum = num;
                int currentStreak =1;

                // count how long this sequence is
                while(numSet.find(currentNum + 1) != numSet.end()){
                    currentNum++;
                    currentStreak++;
                }

                // update the max streak
                longest = max(longest, currentStreak);
            }
        }

        return longest;

        //time Complexity (o(n)) and space O(n)
    }
};
