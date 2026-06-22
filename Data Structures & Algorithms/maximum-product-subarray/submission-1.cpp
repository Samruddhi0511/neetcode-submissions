class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        int curr_max=nums[0];
        int curr_min=nums[0];
        int global_max=nums[0];

        for(int i=1; i<nums.size(); i++){
            int num=nums[i];

            if(num<0){
                swap(curr_max,curr_min);
            }
            curr_max=max(num,curr_max*num);
            curr_min=min(num,curr_min*num);

            global_max=max(global_max, curr_max);
        }

        return global_max;
    }
};
