class Solution {
public:
    int trap(vector<int>& height) {
        // min(leftMax , rightMax)- height[i] for every single position

        if(height.empty()) return 0;

        int left = 0;
         int right = height.size() - 1;

         int leftMax = height[left];
         int rightMax = height[right];

         int waterTrapped = 0;

         while(left < right){

            if(leftMax < rightMax){
                left++;
                leftMax = max(leftMax, height[left]);
                waterTrapped += leftMax - height[left];
            } else {
                right--;
                rightMax = max(rightMax, height[right]);
                waterTrapped += rightMax - height[right];
            }
         }

         return waterTrapped;

         // time compx : O(n)
         // space cpmpx : O(1)
    }
};
