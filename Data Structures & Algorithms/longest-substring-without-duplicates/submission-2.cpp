class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> map;
        int maxLen=0;
        int left=0;
        
        for(int right=0; right<s.size(); right++){
            //if we find a duplicate
            if(map.count(s[right]) && map[s[right]]>=left){
                left=map[s[right]]+1;
            }
            map[s[right]]=right;
            
            maxLen=max(maxLen, right-left+1);
        }
        return maxLen;
    }
};
