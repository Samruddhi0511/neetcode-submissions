#include <string>
#include <unordered_map>
#include <algorithm>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //take every word and sort it
        unordered_map<string, vector<string>> map;
        for(string word:strs){
            string sortedWord=word;
            sort(sortedWord.begin(), sortedWord.end());
            map[sortedWord].push_back(word);
            }
        vector<vector<string>> result;
        for(auto& entry:map){
            result.push_back(entry.second);
        }

        return result;
    }
};
