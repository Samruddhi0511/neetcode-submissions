class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //kth largest
        priority_queue<int, vector<int>, greater<>> max_heap;
        for(int i=0; i<nums.size(); i++){
            max_heap.push(nums[i]);
            if(max_heap.size()>k){
                max_heap.pop();
            }
        }
        return max_heap.top();
    }
};
