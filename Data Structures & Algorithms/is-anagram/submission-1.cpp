class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> s1;
        unordered_map<char,int> t1;

        for(auto frq : s) {
            s1[frq]++;
        }

        for(auto frq : t){
            t1[frq]++;
        }

        return s1 == t1;
    }
};
