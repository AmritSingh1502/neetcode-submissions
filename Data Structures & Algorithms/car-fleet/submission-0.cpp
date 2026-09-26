class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
         int n = position.size();
         if(n == 0) return 0;

         // pair up {position, speed}
         vector<pair<int,int>> cars(n);
         for(int i =0 ; i< n ; i++){
            cars[i] = {position[i], speed[i]};
         }

         // sort by position
         sort(cars.begin(), cars.end());

         stack<double>st;

         // iterrate backward. from the car closest to the target
         for( int i = n -1 ; i >= 0; i--) {
            double time = static_cast<double>(target-cars[i].first)/ cars[i].second;


            // if stack is empty . this car becomes the first fleet leader
            // if its time is > the top of the stack  it is too slow to catch
            // the fleet ahead of it, so it becomes the leadr of a new fleet

            if(st.empty() || time > st.top()){
                st.push(time);
            }

            // otherwise (time <= st.top()) it chaches uo to the fleet and join then
         }

         return st.size();
    }
};
