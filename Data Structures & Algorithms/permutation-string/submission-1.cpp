class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        //base case
        if(s1.size()> s2.size()) return false;
        
        vector<int> s1freq(26,0);
        vector<int> windowFreq(26,0);

        for(char c : s1){
            s1freq[c-'a']++;
        }
        int windowSize=s1.size();
        for(int i=0;i<s2.size();i++){
            windowFreq[s2[i]-'a']++;

            if(i>=windowSize){
                windowFreq[s2[i-windowSize]-'a']--;
            }

            if(s1freq==windowFreq){
                return true;
            }
        }
        return false;
    }
};
