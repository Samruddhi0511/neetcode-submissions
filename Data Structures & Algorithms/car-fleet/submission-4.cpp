class Solution {
public:
    static bool cmp(const pair<int, int>&a, const pair<int, int> &b){
        return a.first>b.first;
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> sorted;
        for(int i=0; i<position.size(); i++){
            sorted.push_back({position[i], speed[i]});
        }
        sort(sorted.begin(), sorted.end(), cmp);
    

    double prevTime=0;int fleet=0;
    for(int i=0; i<sorted.size(); i++){
        double time=(double)(target-sorted[i].first)/ sorted[i].second;
        if(time>prevTime){fleet++;
        prevTime=time;}
    }
    return fleet;
    }
};
