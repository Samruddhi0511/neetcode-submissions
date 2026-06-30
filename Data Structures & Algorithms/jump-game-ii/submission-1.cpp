class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()<=1) return 0;
        int jumps=0; 
        int curr_end=0;
        int furtherest=0;
        for(int i=0; i<nums.size(); i++){
            furtherest=max(furtherest, nums[i]+i);

            if(i==curr_end){
                jumps++;
                curr_end=furtherest;

                if(curr_end >= nums.size()-1) break;
            }
        }
        return jumps;
    }
};
