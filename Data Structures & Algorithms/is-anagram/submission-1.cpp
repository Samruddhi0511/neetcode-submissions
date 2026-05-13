class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size()!=t.size()) return false;
        unordered_map<char, int> maps;
        unordered_map<char, int> mapt;
        for(int i=0; i<s.size(); i++){
            maps[s[i]]++;
            mapt[t[i]]++;
        }

        for(int i=0; i<s.size(); i++){
            char ch=s[i];
            if(maps[ch]!=mapt[ch]) return false;
        }
        return true;
    }
};
