class Solution {
public:
    bool isPalindrome(string s, int start, int end){
        while(start<end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    void backtrack(int idx, vector<string>&curr, string&s, vector<vector<string>>&result){
        if(idx==s.length()){
            result.push_back(curr);
            return;
        }

        for(int i=idx; i<s.size(); i++){
            if(isPalindrome(s, idx, i)){
                curr.push_back(s.substr(idx, i-idx +1));
            
            backtrack(i+1, curr, s, result);
            curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> curr;
        backtrack(0, curr, s, result);
        return result;
    }
};
