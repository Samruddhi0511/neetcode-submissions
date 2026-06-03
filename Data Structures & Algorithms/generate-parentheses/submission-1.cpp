class Solution {
public:
    void backtrack(int n, vector<string>&results, string &curr, int open, int close){
        if(curr.size()==2*n){
            results.push_back(curr);
            return;
        }

        if(close < open){
            curr.push_back(')'); //therev are open brackets without a close bracket
            backtrack(n, results, curr, open, close+1);
            curr.pop_back();

        }

        if(open < n){
            curr.push_back('(');
            backtrack(n, results, curr, open+1, close);
            curr.pop_back();
        }

        
    }
    vector<string> generateParenthesis(int n) {
        
    vector<string> results;
    string curr="";
    int open=0;
    int close=0;
    backtrack(n, results, curr, open , close);
    return results;
    }
};
