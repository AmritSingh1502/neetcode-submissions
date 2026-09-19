class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty() || t.length() > s.length()) return "";

        // track target char require
        vector<int> targetCount(128,0);
        for(char c : t){
            targetCount[c]++;
        }

        // window state
        vector<int> windowCount(128,0);
        int required = 0;

        for( int count : targetCount){
            if(count > 0) required++;
        }

        int formed = 0;
        int left = 0;
        int minLen = INT_MAX;
        int minStart = 0;

        for(int right = 0; right < s.length(); right++){
            char c = s[right];
            windowCount[c]++;
            

            // if the current char matechs the required freq in t
            if(targetCount[c] > 0 && windowCount[c] == targetCount[c]){
                formed++;
            }


            // shrink window from left as long as it contains all charact of t
            while(formed == required){
                // check if current window is the smallest so far
                int currentLen = right - left + 1;
                if(currentLen < minLen){
                    minLen = currentLen;
                    minStart = left;
                }

                char leftChar = s[left];
                windowCount[leftChar]--;

                // if removing the char break the condition
                if(targetCount[leftChar] > 0 && windowCount[leftChar] < targetCount[leftChar]){
                    formed--;
                }
                left++;
            }
        }

        return (minLen == INT_MAX) ? "" : s.substr(minStart, minLen);

    }
};
