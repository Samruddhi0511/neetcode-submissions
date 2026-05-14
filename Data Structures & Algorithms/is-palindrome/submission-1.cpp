
class Solution {
public:
    bool isPalindrome(string s) {
        string str="";
        int i=0;
        while(i<s.size()){
            if(isalnum(s[i])){
                str=str+ static_cast<char>(tolower(static_cast<unsigned char>(s[i])));
            }
            i++;
        }
        
        i=0;int j=str.size()-1;
        while(i<=j){
            if(str[i]!=str[j]) return false;
            i++; j--;
        }
        return true;
        
    }
};
