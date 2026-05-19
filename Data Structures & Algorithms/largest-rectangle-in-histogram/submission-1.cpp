class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea=0;
        for(int i=0; i<heights.size(); i++){
            while(!st.empty() && heights[st.top()]> heights[i]){
                int h=heights[st.top()];
                st.pop();
                
                int right=i;
                int left;
                if (st.empty()) left = -1;
                else left=st.top();
                int area=h*(right-left-1);
                maxArea=max(maxArea, area);
            }
            st.push(i);
        }
        while(!st.empty()){
            int h=heights[st.top()];
            st.pop();
            int right=heights.size();
            int left;
            if(st.empty()) left=-1;
            else left=st.top();
            int area=h*(right-left-1);
            maxArea=max(maxArea, area);
        }
        return maxArea;
    }
};
