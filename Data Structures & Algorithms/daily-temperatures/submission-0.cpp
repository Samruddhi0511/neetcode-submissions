class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> result(temperatures.size(), 0);

        for(int i=0;i<temperatures.size();i++){
            int temp=temperatures[i];
            while(!st.empty() && temp>temperatures[st.top()]){
                int index=st.top();
                result[index]=i-index;
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
};
