class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int x=target[0], y=target[1], z=target[2];
        bool foundx=false, foundy=false, foundz=false;

        for(const auto& triplet : triplets){
            int a=triplet[0], b=triplet[1], c=triplet[2];
            if(a<=x && b<=y && c<=z){
                if(a==x) foundx=true;
                if(b==y) foundy=true;
                if(c==z) foundz=true;
            }
            if(foundx && foundy && foundz) return true;
        }

        return foundx && foundy && foundz;
    }
};
