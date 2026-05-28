class KthLargest {
    priority_queue<int, vector<int>, greater<int>> min_heap;
        int size_limit;
public:
    KthLargest(int k, vector<int>& nums) {
        size_limit=k;
        for(int i : nums){
            add(i);
        }
    }
    
    int add(int val) {
        min_heap.push(val);
        if(min_heap.size() > size_limit){
            min_heap.pop();
        }
        return min_heap.top();
    }
};
