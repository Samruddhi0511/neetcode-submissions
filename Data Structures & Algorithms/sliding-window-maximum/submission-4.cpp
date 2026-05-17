class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // int n=nums.size();
        // int l=0;
        // int r=l+k-1;
        // vector<int> result;
        // while(r<n){
        //     int maxi=INT_MIN;
        //     int i=l;
        //     while(i<=r){
        //         if(nums[i]>maxi){
        //             maxi=nums[i];
        //         }
        //         i++;
        //     }
        //     result.push_back(maxi);
        // l++;
        // r=l+k-1;
        // }
        // return result;

        //ans 2
        //using dequeue
        deque<int> q;
        vector<int> result;
        int l=0;
        for(int r = 0; r<nums.size(); r++){
            while(!q.empty() && (nums[q.back()]<=nums[r])){
                q.pop_back();
            }

            q.push_back(r);

            if(q.front()<l){
                q.pop_front();
            }
            if(r>=k-1){
                result.push_back(nums[q.front()]);
                l++;
            }
        }
        return result;
    }
};
