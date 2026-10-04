class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // phase 1 find intersection point
        int slow = nums[0];
        int fast = nums[nums[0]];

        // advace slow 1 step and fast 2 steps
        while(slow != fast){
            slow  = nums[slow];
            fast = nums[nums[fast]];
        }

        // phase 2 find the enterance to the cycle (the duplicate number)
        slow = 0;

        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
