class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        // count frequency 
        Map<Integer, Integer> count = new HashMap<>();
        for(int num : nums){
            count.put(num, count.getOrDefault(num, 0 ) + 1);
        }

        // 2. bucket array with index = frqu
        List<Integer>[] buckets = new List[nums.length + 1];
        for( int key : count.keySet()){
            int freq = count.get(key);
            if(buckets[freq] == null){
                buckets[freq] = new ArrayList<>();
            }

            buckets[freq].add(key);
        }

        // 3.colllect top k elemnent starting from the end

        int[] result = new int[k];
         int index = 0;

         for( int freq = buckets.length -1 ; freq >= 0 && index < k ; freq--){
            if(buckets[freq] != null){
                for( int num : buckets[freq]){
                    result[index++] = num;
                    if(index == k) break;
                }
            }
         }

         return result;
    }
}
