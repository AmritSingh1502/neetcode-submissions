class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while(left < right){
            // skip non-alphanumeric characters from left
            while(left < right && !isalnum(s[left])){
                left++;
            }

            // skip non-alphanumeric char from right
            while(left < right && !isalnum(s[right])){
                right--;
            }

            // compare the valid char in lowercase
            if(tolower(s[left]) != tolower(s[right])){
                return false;
            }

            left++;
            right--;
        }

        return true;

        // time compx : 0(n)
        //space compx : O(1)
    }
};
