class Solution {
public:

    string encode(vector<string>& strs) {
        //the input is a vector of strings
        //iterate thru the vector , and store the size of each string

        if(strs.empty()) return "";
        vector<int> sizes;
        for(string i: strs){
            sizes.push_back(i.size());
        }

        string result="";
        for(int i:sizes){
            result=result + to_string(i)+',';
        }

        result=result+'#';
        for(string s:strs){
            result = result+ s;
        }

        return result;
    }

    vector<string> decode(string s) {
        if (s.size()==0) return {};
        vector<int> sizes;
        vector<string> result;
        int i=0;
        while(s[i]!='#'){
            string curr="";
            while(s[i]!=','){
                curr=curr+s[i];
                i++;
            }
            sizes.push_back(stoi(curr));
            i++;
        }
        i++;
        for(int j:sizes){
            result.push_back(s.substr(i,j ));
            i=i+j;
        }

        return result;
    }
};
