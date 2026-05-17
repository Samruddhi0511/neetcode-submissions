class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int r=l+k-1;
        vector<int> result;
        while(r<n){
            int maxi=INT_MIN;
            int i=l;
            while(i<=r){
                if(nums[i]>maxi){
                    maxi=nums[i];
                }
                i++;
            }
            result.push_back(maxi);
        l++;
        r=l+k-1;
        }
        return result;
    }
};
