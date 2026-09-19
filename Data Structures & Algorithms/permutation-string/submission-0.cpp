class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;

        vector<int> s1Count(26,0);
        vector<int> windowCount(26,0);
        int windowSize = s1.length();

        // poplulate freq for s1 and the very first window of s2

        for( int i = 0 ; i < windowSize ; i++){
            s1Count[s1[i]-'a']++;
            windowCount[s2[i]-'a']++;
        }

        //check if  the first window happens to be a perfect match
        if(s1Count == windowCount) return true;

        // slide the window acrss the rest of s2
        for( int i = windowSize; i < s2.length(); i++){
            // add the cahr entering the window on the right
            windowCount[s2[i]-'a']++;

            // remove the old char
            windowCount[s2[i-windowSize]-'a']--;

            // if char count match we found
            if(s1Count == windowCount) return true;
        }

        return false;

        // time compx : O(n)

    }
};
