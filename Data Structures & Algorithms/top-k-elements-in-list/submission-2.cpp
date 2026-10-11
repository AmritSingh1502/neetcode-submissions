class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // revision version : 01
        unordered_map<int,int> count;

        for(int num : nums){
            count[num]++;
        }

        // freq : {freq --> [list of elements]}
        map<int,vector<int>, greater<int>> frqMap;

        for(const auto& pair : count){
            int element = pair.first;
            int freq = pair.second;

            frqMap[freq].push_back(element);
        }

        // extract top k

        vector<int> res;
        for(const auto& pair : frqMap){
            for(int num : pair.second){
                res.push_back(num);
                if(res.size() == k) return res;
            }
        }
        return res;
    }
};
