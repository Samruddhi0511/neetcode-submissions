#include <string>
class Solution {
public:
    bool isPalindrome(string s) {
        int start=0;
        int end=s.size()-1;
        while(end>=start){
            if(!isalnum(s[end])){
                end--;
                continue;
            }
            if(!isalnum(s[start])){
                start++;
                continue;
            }
            //the updati
            if(tolower(s[start])!=tolower(s[end])){
                return false;
            }
        
                start++;
                end--;
            
        }
        return true;
    }
};
