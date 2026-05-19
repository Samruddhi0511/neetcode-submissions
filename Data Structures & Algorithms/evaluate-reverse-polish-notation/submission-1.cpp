class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0; i<tokens.size(); i++){
            string ch=tokens[i];
            if(ch=="+" || ch=="-" || ch=="*" || ch=="/"){
                int op2=st.top();
                st.pop();
                int op1=st.top();
                st.pop();
                if(ch == "+") st.push(op1 + op2);

                else if(ch == "-") st.push(op1 - op2);

                else if(ch == "*") st.push(op1 * op2);

                else st.push(op1 / op2);
            }
            else{
                st.push(stoi(ch));
            }
        }
        return st.top();
    }
};
