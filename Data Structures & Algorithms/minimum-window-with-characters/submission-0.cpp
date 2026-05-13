class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for(char c:t){
            need[c]++;
        } 
        int left=0; int right=0; int have=0; int needCount=need.size();
        int minStart=0; int minLen=INT_MAX;

        while(right<s.size()){
            char c=s[right];
            window[c]++;

            if(need.count(c) && window[c]==need[c]){
                have++;
            }
            while(have==needCount){
                //try to shrink the size
                if(right-left+1<minLen){
                    minLen=right-left+1;
                    minStart=left;
                }
                char lChar=s[left];
                window[lChar]--;
                if(need.count(lChar) && window[lChar]<need[lChar]){
                    have--;
                }
                left++;
            }
            right++;
        }

        return minLen==INT_MAX ? "":s.substr(minStart, minLen);
    }
};
