class LRUCache {
public:
    list<pair<int, int>> dll;
    unordered_map<int, list<pair<int, int>> :: iterator> map;
    int cap;
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(map.find(key)==map.end()) return -1;

        auto it=map[key];
        int value=it->second;

        dll.erase(it);
        dll.push_front({key, value});
        map[key]=dll.begin();
        return value;
    }
    
    void put(int key, int value) {
        if(map.find(key)!=map.end()){
            dll.erase(map[key]);
            map.erase(key);
        }

        dll.push_front({key, value});
        map[key]=dll.begin();
        if(dll.size()>cap){
            auto last=dll.back();
            map.erase(last.first);
            dll.pop_back();
        }
        
    }
};
