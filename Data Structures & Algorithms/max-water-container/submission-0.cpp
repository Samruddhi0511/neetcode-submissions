class Solution {
public:
    int maxArea(vector<int>& heights) {
        int start=0;
        int end=heights.size()-1;
        int area=0;
        while(end>start){
            int min_height=min(heights[start], heights[end]);
            int temp_area=min_height*(end-start);
            area=max(area, temp_area);
            if(heights[start]<heights[end]){
                start++;
            }
            else{
                end--;
            }
        }
        return area;
    }
};
