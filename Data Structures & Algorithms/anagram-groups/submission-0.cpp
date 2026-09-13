class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;
        vector<vector<string>> ans;

        for(const auto& str : strs){
            string key(26,0);


            for(char c: str){
                key[c - 'a']++;
            }

            mpp[key].push_back(str);
        }

        ans.reserve(mpp.size());

        for(auto& pair : mpp){
            ans.push_back(move(pair.second));
        }

        return ans;
    }
};
