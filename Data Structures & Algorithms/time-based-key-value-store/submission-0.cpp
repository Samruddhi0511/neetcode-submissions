class TimeMap {
public:
    TimeMap() {
        
    }
    //storing is of the format key: [(timestamps, values), (timestamp, value)..and so on]

    unordered_map<string, vector<pair<int, string>>> key_time_value;
    
    void set(string key, string value, int timestamp) {
        key_time_value[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        //if key isnt there
        if(key_time_value.find(key)==key_time_value.end()){
            return "";
        }
        vector<pair<int, string>>& target_timestamps=key_time_value[key];
        int left=0;
        int right=target_timestamps.size(); // if value is greater than all the left will stop at last index but left-1 will return second last largest element
        while(left<right)
        //we donot want to match perfectly lesser than is find
        {
            int mid=left+(right-left)/2;
            if(target_timestamps[mid].first<=timestamp) //possible value but vll still search for a greater value
            left=mid+1;
            else
            //mid can b a possible value
            right=mid;
        }
        if(left==0)
            return ""; //timestamp entered is less than the lowest value
        

        return target_timestamps[left-1].second;
    }
};
