class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        //all the numbers are there in the set now
        int longest=0; // will get the longest seq

        for(int i=0;i<nums.size();i++){
            if(numSet.find(nums[i]-1)==numSet.end()){
                int currentNum=nums[i];
                int currentStreak=1; //start the sequence

                while(numSet.find(currentNum+1)!=numSet.end()){
                    currentNum=currentNum+1;
                    currentStreak=currentStreak+1;
                }

                longest=max(longest, currentStreak);
            }
            
        }
        return longest;
    }
};
