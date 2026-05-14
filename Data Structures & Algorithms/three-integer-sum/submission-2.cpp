class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-2; i++){
            if(i!=0 && nums[i]==nums[i-1]) continue;

            int left=i+1; int right=nums.size()-1;
            while(left<right){
                int sum=nums[right]+nums[left];
                if(sum==(-nums[i])){
                    result.push_back({nums[i], nums[right], nums[left]});
                    while(left<right && nums[left+1]==nums[left]) left++;
                    while(left<right && nums[right-1]==nums[right]) right--;
                    left++;
                    right--;
                    
                }
                else if(sum>(-nums[i])){
                    right--;
                }
                else{
                    left++;
                }

                
            }
        }
        return result;
    }
};
