//timestamps strictly increasing hence, binary search
class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> map;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>> temp=map[key];
        string str="";
        int l=0; int h=temp.size()-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(temp[mid].first == timestamp){
                str=temp[mid].second;
                break;
            }
            else if(temp[mid].first<timestamp){
                str=temp[mid].second;
                l=mid+1;
            }
            else h=mid-1;
        }
        return str;
    }
};
