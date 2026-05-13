class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0; int j=nums.size()-1;
        vector<int> result;
        
        unordered_map<int, int> map;
        for(int i=0; i<nums.size(); i++){
            map[nums[i]]=i;
        }

        for(int i=0; i<nums.size(); i++){
            int a=target-nums[i];
            if(map.find(a)!=map.end() && map[a]!=i){
                result.push_back(i);
                result.push_back(map[a]);
                break;
            }
        }
        return result;
    }
};
