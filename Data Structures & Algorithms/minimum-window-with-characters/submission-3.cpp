class Solution {
public:


    string minWindow(string s, string t) {
        unordered_map<char, int> mapt, maps;
        for(char i : t){
            mapt[i]++;
        }

        int l=0, minLen=INT_MAX, start=0;
        int need=mapt.size(), have=0;
        
        for(int r=0; r<s.size(); r++){
            maps[s[r]]++;
            if(mapt.count(s[r]) && mapt[s[r]]==maps[s[r]]){
                have++;
            }

            while(have==need){
                if(r-l+1<minLen){
                    minLen=r-l+1;
                    start=l;
                }
                maps[s[l]]--;
                if(mapt.count(s[l]) && maps[s[l]]<mapt[s[l]]){
                    have--;
                }
                l++;
            }
        }

        return minLen==INT_MAX ? "" : s.substr(start, minLen);
    }
};
