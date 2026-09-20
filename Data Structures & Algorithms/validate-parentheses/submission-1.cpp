class Solution {
public:
    bool isValid(string s) {
        stack<char>st;

        for(char c : s){
            // push expected closing bracket on the stack
            if(c == '('){
                st.push(')');
            } else if (c == '{'){
                st.push('}');
            } else if( c== '['){
                st.push(']');
            } else {
                // if stack empty or the top doesnt match the current closing bractlet
                if(st.empty() || st.top() != c){
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};
