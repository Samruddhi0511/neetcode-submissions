#include <algorithm>
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size(); //0 to n
        int sum = (n*(n+1))/2;
        int sum1=accumulate(nums.begin(), nums.end(),0);
        if(sum==sum1) return 0;
        return sum-sum1;
    }
};
