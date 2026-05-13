class Solution {
public:
    int search(vector<int>& nums, int target) {
        //edge case
        if(nums.size()==1 && target==nums[0]){
            return 0;
        }
       
        int left=0;
        int right=nums.size()-1;


        while(right>left){
            //first v find the cut
            int mid=left+(right-left)/2;
            if(nums[mid]>nums[right]){
                // this means taht the cut lies to the right side
                left=mid+1;
            }
            else{
                right=mid;
            }
        }
        int cut=left;
        
         left=0;
        right=nums.size()-1;
        while(right>=left){
                int mid=left+(right-left)/2;
                int realmid=(mid+cut)%nums.size();
                if(nums[realmid]==target){
                    return realmid;
                }
                else if(target>nums[realmid]){
                    left=mid+1;
                }
                else{
                    right=mid-1;
                }
        }
    return -1;
}

    }

;
