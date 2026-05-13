class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_set<char> seen;
        int left=0;
        int maxLength=0;
        int maxCount=0;
        vector<int> freq(26,0);

        for(int right=0;right<s.size();right++){
            freq[s[right]-'A']++;
            maxCount=max(maxCount, freq[s[right]-'A']);

            int windowSize=right-left+1;
            if(windowSize-maxCount>k){
                freq[s[left]-'A']--;
                left++;
            }

            maxLength=max(maxLength, right-left+1);
        }

return maxLength;

    }
};
