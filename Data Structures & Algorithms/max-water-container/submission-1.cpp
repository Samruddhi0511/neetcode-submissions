class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left=0; int right=heights.size()-1;
        int ans=0;
        while(left<right){
            int area=(right-left)*min(heights[left], heights[right]);
            ans=max(ans, area);
            if(heights[left]>heights[right]) right--;
            else left++;
        }
        return ans;
    }
};
