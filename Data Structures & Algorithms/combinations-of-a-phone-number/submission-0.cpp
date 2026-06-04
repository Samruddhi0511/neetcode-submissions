class Solution {
public:
    //mapping
    vector<string> keypad = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void backtrack(int idx, string&digits, string&curr, vector<string>&result){
        if(curr.length()==digits.length()){
            result.push_back(curr);
            return;
        }

        int digit=digits[idx]-'0';

        string letters=keypad[digit];

        for(int i=0; i<letters.length(); i++){
            curr.push_back(letters[i]);
            backtrack(idx+1, digits, curr, result);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
      vector<string> result;
      if (digits.length()==0) return result;
      string curr="";
      backtrack(0, digits, curr, result);
      return result;
    }
};
