class Solution {
public:
    bool isvalid(int k, vector<int> piles, int h){
        int time=0;
        for(int i=0; i<piles.size(); i++){
            time+= ceil((double)piles[i]/k);
        }
        if(time<=h) return true;
        return false;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(), piles.end());
        int ans;
        while(l<=r){
            int mid=(l+r)/2;
            if(isvalid(mid, piles, h)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }

        }
        return ans;
    }
};
