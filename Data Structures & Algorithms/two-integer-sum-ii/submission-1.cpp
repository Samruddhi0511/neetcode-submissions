class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>result;

        int i=0; int j=numbers.size()-1;
        while(i<j){
            int sum=numbers[i]+numbers[j];
            if(sum==target){
                result.push_back(i+1);
                result.push_back(j+1);
                break;
            }
            if(sum>target){
                j--;
            }
            else{
                i++;
            }
        }
        return result;
    }
};
