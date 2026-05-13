#include <unordered_map>
#include <list>
class LRUCache {
    private:
    struct Node {
        int key;
        int value;
        Node(int k, int v) : key(k), value(v) {}
    };
    
    int capacity;
    std::list<Node> cacheList;
    std::unordered_map<int, std::list<Node>::iterator> cacheMap;
public:
    
    
    
    LRUCache(int capacity): capacity(capacity) {
        
    }
    
    int get(int key) {

        //if the key is not found in the map then return -1
        if(cacheMap.find(key)==cacheMap.end()){
            return -1;
        }
        //move the accessed element to the front
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        return cacheMap[key]->value;
    }
    
    void put(int key, int value) {
        //if already exists
        if(cacheMap.find(key)!=cacheMap.end()){
            //update
            cacheMap[key]->value=value;
            //move to the front
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            return;
        }
        //if the capacity is reached
        if(cacheList.size()==capacity){
            //pop from the back and erase from the map
            cacheMap.erase(cacheList.back().key);
            cacheList.pop_back();}

            //addd new
            cacheList.emplace_front(key, value);
            cacheMap[key]=cacheList.begin();
        
        
    }
};
