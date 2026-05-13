class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int> result;

        for(int i=0;i<nums.size();i++){
            //first v cehck if the deque is not empty and if it exists in the current window
            if(!dq.empty() && dq.front()<=i-k){
                //since valid window is from i-k+1 to i
                dq.pop_front();
            }

            //remove the tiny numbers
            while(!dq.empty() && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
    }
};
