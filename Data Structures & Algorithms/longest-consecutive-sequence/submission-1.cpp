class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int i: nums){
            map[i]++;
        }
        int ans=0;
        int curr;

        for(int i=0; i<nums.size(); i++){
            //find the smallest in the range
            int curr=nums[i];
            if(map.find(curr-1)!=map.end()){
                continue;              
            }
            int currLen=1;
            while(map.find(curr+1)!=map.end()){
                currLen++;
                curr=curr+1;
                      
            }

            ans=max(ans, currLen);
        }

        return ans;
    }
};
