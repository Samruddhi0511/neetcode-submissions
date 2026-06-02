class MedianFinder {
priority_queue<int> maxheap;
priority_queue<int, vector<int>, greater<int>> minheap;
public:

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxheap.push(num);
        minheap.push(maxheap.top());
        maxheap.pop();
        if(minheap.size()>maxheap.size()){
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() {
        if(minheap.size()==maxheap.size()){
            return (minheap.top()+maxheap.top())/2.0;
        }
        return maxheap.top();
    }
};
