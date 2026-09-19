class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // monotonically decreasing queue
        // deque
        vector<int> result;
        deque<int> dq; // stores indices of elements in monotonically decreasinog oredr

        for( int i = 0 ; i< nums.size(); i++){
             // remove indices that are out of the current window bound [i- k + 1];
             if(!dq.empty() && dq.front() <= i -k){
                dq.pop_front();
             }

             // maintain monotonic decreasing oredr
             // remvoe smaller elem from the back 
             while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
             }

             // add current eleemen's index
             dq.push_back(i);

             // once we have prrocessed at least k elements recorde the curretn window max
             if(i >= k - 1){
                result.push_back(nums[dq.front()]);
             }
        }
        return result;
    }
};
