class Solution {
public:

    string encode(vector<string>& strs) {
        string final_string="";
    for(int i=0;i<strs.size();i++){
        string s=strs[i];
        int length=strs[i].size();
        string len=to_string(length);
        string c="#";

        string str=len.append(c);
        str=str.append(s);
        final_string=final_string.append(str);
        
    }
    return final_string;

    }

    vector<string> decode(string s) {
        vector<string> result;
    int i=0;
    int length;
    while(i<s.size()){
        //find # operator
        int j=i;
        while(s[j]!='#'){
            j++;
        }
        
            length=stoi(s.substr(i,j-i)); //gives number before the hash eg 10#something, j is at 2 i is at 0, therefore length is 2-0 is 3
            string str=s.substr(j+1, length);
            result.push_back(str);
        
        i=j+length+1;
        
    }
    return result;
        
    }
};
