class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //add a zero to the end so that all the elemnts are processed even if the histogram is non decreasing
        heights.push_back(0);

        stack<int> st;

        int max_area=0;

        for(int i=0;i<heights.size();i++){
            // when there is obstruction by a shorter bar, calculate area
            while(!st.empty() && heights[i]< heights[st.top()]){
                int height=heights[st.top()];

                st.pop();

                int width=st.empty()?i : i-st.top()-1;

                max_area=max(max_area, height*width);
            }
            st.push(i);
        }
        return max_area;
    }
};
