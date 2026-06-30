class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumgas=0; int sumcost=0;
        for(int i=0; i<gas.size(); i++){
            sumgas+=gas[i];
            sumcost+=cost[i];
        }
        if(sumgas<sumcost) return -1;
        int tank=0;
        int start=0;
        for(int i=0; i<gas.size(); i++){
            tank=tank + (gas[i]-cost[i]);
            if(tank < 0){
                tank=0;
                start=i+1;
            }
        }
        return start;
    }
};
