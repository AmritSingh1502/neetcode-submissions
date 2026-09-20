class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> seen = new HashMap<>(); // value --> index

        for( int i = 0; i < nums.length; i++){
            int complement = target - nums[i];

            // check if compleemnt has been 

            if(seen.containsKey(complement)){
                return new int[] {seen.get(complement), i};
            }

            // store the current number and its index
            seen.put(nums[i], i );
        }

        return new int[]{};


    }
}
