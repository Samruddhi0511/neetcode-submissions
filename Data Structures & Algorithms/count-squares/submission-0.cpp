#include <cstring>
class CountSquares {
    int counts[1001][1001];
    vector<pair<int, int>> points;
public:
    CountSquares() {
        memset(counts,0, sizeof(counts));
    }
    
    void add(vector<int> point) {
        if(counts[point[0]][point[1]]==0){
            points.push_back({point[0], point[1]});
        }
        
            counts[point[0]][point[1]]++;
        
    }
    
    int count(vector<int> point) {
        int x1=point[0];
        int y1=point[1];
        int total=0;
        for(auto& p : points){
            if(p.first==x1 || p.second==y1) continue;
            if(abs(x1-p.first)!=abs(y1-p.second)) continue;

            int p2_count=counts[x1][p.second];
            int p3_count=counts[p.first][p.second];
            int p4_count=counts[p.first][y1];
            total+=(p3_count*p4_count*p2_count);
        }

        return total;
    }
};
