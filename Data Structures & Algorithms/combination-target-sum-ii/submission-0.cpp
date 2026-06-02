class Solution {
public:
    void generate(int idx, vector<int>& candidates, vector<int>&curr,vector<vector<int>>&result, int target){
        if(target==0){
            result.push_back(curr);
            return;
        }
        if(target<0) return;

        for(int i=idx; i<candidates.size(); i++){
            if(i>idx && candidates[i]==candidates[i-1]) continue;
            curr.push_back(candidates[i]);
            generate(i+1, candidates, curr, result, target-candidates[i]);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        generate(0, candidates, curr, result, target);
    
        return result;
    }
};
