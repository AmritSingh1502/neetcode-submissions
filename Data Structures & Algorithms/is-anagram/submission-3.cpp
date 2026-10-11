class Solution {
public:
    bool isAnagram(string s, string t) {

        // revison version : 01
        unordered_map<char, int> s1;
        unordered_map<char, int> t1;

        for (auto chars : s){
            s1[chars]++;
        }

        for(auto chart : t){
            t1[chart]++;
        }

        return s1 == t1;
    }
};
