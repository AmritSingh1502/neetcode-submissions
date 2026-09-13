class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // count freq {ele --> frq}
        unordered_map<int,int> countMap;

        for( int num : nums){
            countMap[num]++;
        }

        //group by freq : {freq --> [list of elements]}
        map<int,vector<int>, greater<int>> freqMap;

        for(const auto& pair : countMap){
             int element = pair.first;
             int frequency = pair.second;

             freqMap[frequency].push_back(element);
        }

        // extract the top k elements
        vector<int> result;
        for(const auto& pair : freqMap){
            for(int num : pair.second){
                result.push_back(num);
                if(result.size() ==k) return result;
            }
        }

        return result;

        //o(n). time and space compxty: using bucket sort , can be solved using min heap.
    }
};
