class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        // monotonic decreasing oredr stack
        int n = temperatures.length;
        int[] answer = new int[n];
        Deque<Integer> stack = new ArrayDeque<>(); // store indices

        for( int i = 0 ; i< n ; i++){
            // while current temp is greateer than the  temp at index stored at stack top
            while(!stack.isEmpty() && temperatures[i] > temperatures[stack.peek()]){
                int prevIndex = stack.pop();
                answer[prevIndex] = i  - prevIndex;
            }
            stack.push(i);
        }
        return answer;
    }
}
