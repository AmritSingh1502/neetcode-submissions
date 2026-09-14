class Solution {
public:
    int maxArea(vector<int>& heights) {
        // brute force O(n)
    //      int ans = 0;
    //      for( int i = 0 ; i < heights.size(); i++){
    //         for( int j = i+ 1; j < heights.size(); j++){
    //             int area =( j - i) * min(heights[i], heights[j]);
    //             ans = max(ans, area);
    //         }
    //      }
    //      return ans;
    // }

    // optimal soln : two pointers

    int ans = 0;
    int left =0;
     int right = heights.size() - 1;

     while(left < right){
        int area = (right - left) * min(heights[left], heights[right]);
        ans = max(area, ans);

        //move the pointer of the shorter line inward
        if(heights[left] < heights[right]){
            left++;
        } else {
            right--;
        }
     }
     return ans;
     // time cmpx : O(n)
     // space cmpx : O(1)
    }
};
