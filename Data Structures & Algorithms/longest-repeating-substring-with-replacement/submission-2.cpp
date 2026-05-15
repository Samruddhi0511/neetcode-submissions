class Solution {
public:
    int findmaxfreq(int l, int r, string s){
        unordered_map<char, int> map;
        for(int i=l; i<=r; i++){
            map[s[i]]++;
        }
        int maxi=0;
        for(auto it: map){
            maxi=max(it.second, maxi);
        }
        return maxi;
    }

    int characterReplacement(string s, int k) {
        int l=0; int r=0; int maxLen=0;
        for(r=0;r<s.size(); r++){
            //we need to know how many replacements in curr window
            int maxFreq=findmaxfreq(l,r,s);

            int replacements=(r-l+1)-maxFreq;
            while((r-l+1-maxFreq)>k){
                l++;
            }
            maxLen=max(maxLen, r-l+1);
        }
        return maxLen;
    }
};
