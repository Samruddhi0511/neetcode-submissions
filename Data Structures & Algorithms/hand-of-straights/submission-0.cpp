class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize !=0) return false;
        unordered_map <int, int> map;
        for(int n : hand){
            map[n]++;
        }

        priority_queue<int> maxheap;
        for(auto& pair : map){
            maxheap.push(pair.first);
        }

        while(!maxheap.empty()){
            int maxi=maxheap.top();
            if(map[maxi]==0){
                maxheap.pop(); continue;
            }

            for(int i=0; i<groupSize ; i++){

                int curr = maxi-i;
                if(map[curr]==0) return false;
                map[curr]--;
        }
        }

return true;
    }
};
