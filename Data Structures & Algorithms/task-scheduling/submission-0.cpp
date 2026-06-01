class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(char t : tasks){
            freq[t-'A']++;
        }

        priority_queue<int> max_heap;
        for(int f : freq){
            if(f>0) max_heap.push(f);
        }
        int cycles=0;
        while(!max_heap.empty()){
            vector<int> temp;
            for(int i=0; i<=n ; i++){
                if(!max_heap.empty()){
                    temp.push_back(max_heap.top());
                    max_heap.pop();
                }
                
            }
            for(int t : temp){
                if (t-1>0) max_heap.push(t-1);
            }
            //if max heap isnt empty more tasks are remaining
            if(!max_heap.empty()) cycles=cycles+n+1;
            else cycles += temp.size();

            
        }

        return cycles;    
        
    }
};
