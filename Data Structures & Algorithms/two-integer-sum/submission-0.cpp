#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(int i=0;i<nums.size();i++){
            int complement=target-nums[i];
            
            //in eg, 4, 5,6..target=10 10-4=6
            if(map.count(complement)){//if 6 is present then
                if(map[complement]>i){
                return {i, map[complement]};
                }
                else{
                    return {map[complement], i};
                }
            }

            map[nums[i]]=i;
        }
    }
};
