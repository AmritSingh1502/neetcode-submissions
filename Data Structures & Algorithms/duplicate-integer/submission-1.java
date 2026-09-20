class Solution {
    public boolean hasDuplicate(int[] nums) {
        Set<Integer> hashSet = new HashSet<>();
        for( int num : nums){
            // add retuirn false if the elem already present in the set
            if(!hashSet.add(num)){
                return true;
            }
        }
        return false;
    }
}