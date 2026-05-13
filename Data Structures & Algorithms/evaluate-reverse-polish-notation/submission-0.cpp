class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> st;
        for(int i=0;i<tokens.size();i++){
            string token=tokens[i];
            if(token != "+" && token != "-" && token != "*" && token != "/"){
                st.push(stoi(token));
            }
            else{
                int op1=st.top();
                st.pop();
                int op2=st.top();
                st.pop();
                int ans=0;
                if(token=="+"){
                    ans=op1+op2;
                }
                else if(token=="-"){
                    ans=op2-op1;
                }
                else if(token=="*"){
                    ans=op2*op1;
                }
                else{
                    ans=op2/op1;
                }
                st.push(ans);
            }

            
        }
        return st.top();
    }
};
