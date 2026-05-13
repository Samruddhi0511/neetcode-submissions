class Solution {
public:
    int findMin(vector<int> &nums) {
        int left=0;
        int right=nums.size()-1;
        while(right>left){
            int mid=left+(right-left)/2;

            if(nums[right]<nums[mid]){
                //min lies in the right
                left=mid+1;
            }
            else{
                right=mid;
            }
        }
        return nums[left];
    }
};
