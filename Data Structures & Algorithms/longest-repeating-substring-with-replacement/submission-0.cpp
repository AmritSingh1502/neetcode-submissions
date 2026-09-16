class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> counts(26,0);
        int left = 0;
        int maxFreq = 0; // count of the most freq char in the current window
        int maxLen = 0;

         for( int right = 0; right < s.size(); right++){
            // add the new char to our window
            counts[s[right] - 'A']++;

            // update the max frq seen in any window so far
            maxFreq = max(maxFreq, counts[s[right]- 'A']);

            // current widnow size is (right - left + 1)
            // no of replacements needed = window size - maxFreq
            // if replacements needed excedded k, the window is invalid
            if((right - left + 1) -maxFreq > k){
                // shrink the window from left
                counts[s[left]- 'A']--;
                left++;
            }

            // record the max valid widnow size
            maxLen = max(maxLen , right - left + 1);
         }
         return maxLen; 
    }
};
