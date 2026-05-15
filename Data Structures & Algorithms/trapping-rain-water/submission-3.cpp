class Solution {
public:
    int trap(vector<int>& height) {
        //water trapped at any index= min(height[left], height[right])- height[i]
        //prefix finds the tallest to the left
        //suffix finds the tallest to the right

        vector<int> leftMax(height.size()), rightMax(height.size());
        leftMax[0]=height[0];
        for(int i=1; i<height.size();i++){
            leftMax[i]=max(leftMax[i-1], height[i]);
        }
        rightMax[height.size()-1]=height[height.size()-1];
        for(int i=height.size()-2; i>=0; i--){
            rightMax[i]=max(rightMax[i+1], height[i]);
        }

        int total=0;
        for(int i=0; i<height.size(); i++){
            total=total+min(leftMax[i], rightMax[i])-height[i];
        }
        return total;
    }
};
