class MinStack {
    private Deque<Integer> mainStack;
    private Deque<Integer> minStack;

    public MinStack() {
        mainStack = new ArrayDeque<>();
        minStack = new ArrayDeque<>();    
    }
    
    public void push(int val) {

        mainStack.push(val);
        // push to minStack if its empty or val is <= current min
        if(minStack.isEmpty() || val <= minStack.peek()){
            minStack.push(val);
        }
        
    }
    
    public void pop() {
        // use equals() because peek() returns an Integer object
        if(mainStack.peek().equals(minStack.peek())){
            minStack.pop();
        }

        mainStack.pop();
    }
    
    public int top() {
        return mainStack.peek();
    }
    
    public int getMin() {
        return minStack.peek();
    }
}
