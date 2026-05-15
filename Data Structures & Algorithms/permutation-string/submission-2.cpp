class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        int n=s1.size();
        int l=0;
        unordered_map<char, int> map1;
        for(int c : s1){
            map1[c]++;
        }
        while(l<=s2.size()-n){
            int r=l+n-1;
            unordered_map<char, int> map2;
            for(int i=l; i <=r; i++){
                map2[s2[i]]++;
            }
            if(map1==map2) return true;
            l++;

        }
        return false;
    }
};
