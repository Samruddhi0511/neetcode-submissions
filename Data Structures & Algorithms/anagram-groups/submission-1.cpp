class Solution {
public:
    unordered_map<char, int> getMap(string s){
        unordered_map<char, int> map;
        for(int i = 0; i < s.size(); i++){
            map[s[i]]++;
        }
        return map;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        for(int i=0; i<strs.size(); i++){
            unordered_map<char, int> map;
            map=getMap(strs[i]);

            if(result.empty()){
                vector<string> temp;
                temp.push_back(strs[i]);
                result.push_back(temp);
                continue;
            }

            //iterate thru all the vectors in the result
            int j;
            bool found = false;
            for(j=0; j<result.size(); j++){
                string s=result[j].back();
                unordered_map<char, int> temp1;
                temp1=getMap(s);
                if(map==temp1){
                    result[j].push_back(strs[i]);
                    found = true;
                    break;
                }
            }
            if (!found){
                //have checked all and didnt find anagram
                vector<string> temp;
                temp.push_back(strs[i]);
                result.push_back(temp);
                continue;

            }
        }
        return result;
    }
};
