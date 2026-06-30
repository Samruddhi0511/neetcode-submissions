class Solution {
public:
    bool canJump(vector<int>& nums) {
       if(nums.size()<=1) return true;
       int curr_End=0;
       int far=0;
       for(int i=0; i<nums.size(); i++){
        far=max(far, nums[i]+i);
        if(i==curr_End){
            curr_End=far;
            if(curr_End>=nums.size()-1) return true;
        }
       }
       return false;
    }
};
