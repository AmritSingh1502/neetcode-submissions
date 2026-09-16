class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;

        int left = 0;
        int maxLen = 0;
        
        for( int right = 0 ; right< s.size(); right++){
            // while the current char already in set,
            // remove the leftmost char and shrink the window
            while(charSet.count(s[right])){
                charSet.erase(s[left]);
                left++;
            }

            // now it's safe to add the new char
            charSet.insert(s[right]);

            // update the max len found
            maxLen = max(maxLen , right- left + 1);
        }

        return maxLen;
    }
};
