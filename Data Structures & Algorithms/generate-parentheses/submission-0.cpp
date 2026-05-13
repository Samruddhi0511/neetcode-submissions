class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        stack <pair<string, pair<int,int>>> st;
        st.push({"",{ 0, 0}});

        while(!st.empty()){
            pair<string, pair<int,int>> pr =st.top();
            string current=pr.first;
            int open=pr.second.first;
            int close=pr.second.second;
            st.pop();

            if(current.length()==2*n){
                result.push_back(current);
            }
            if(open<n){
                st.push({current+'(', {open+1, close}});
            }
            if(close<open){
                st.push({current+')',{open, close+1}});
            }
        }
        return result;
    }
};
