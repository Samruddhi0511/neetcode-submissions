#include <unordered_map>
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
        return false;
    }
    //using hash map
    unordered_map<char, int> count;
    for(char c:s){
        count[c]++;
    } 
    for(char c:t){
        count[c]--;
        //if any different alphabet exists, its count will be negative
        if(count[c]<0){
            return false;
        }
    }
    return true;
        
    }
};
