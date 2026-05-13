class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        int middle=start+((end-start)/2);

        while(end>=start){
            if(nums[middle]==target){
                return middle;
            }
            else if(target> nums[middle]){
                start=middle+1;
            }
            else{
                end=middle-1;
            }
            middle=start+((end-start)/2);

        }
        return -1;
    }
};
