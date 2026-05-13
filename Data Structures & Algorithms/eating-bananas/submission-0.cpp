class Solution {
public:
    bool totalHours(vector<int>& piles, int k, int h){
        int hours=0;
        for(int pile : piles){
            hours+=(pile+k-1)/k;
        }
        if(hours<=h){
            return true;
        }
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(), piles.end());
        int mid=low+(high-low)/2;

        while(high>low){
            if(totalHours(piles, mid, h)) //this k is possible now v try a smaller k
            high=mid; //v rnt matching values so v donot need to elimiate mid like in clasisc binary search

            else{
                low=mid+1;
            }
            mid=low+(high-low)/2;
        }
        return low;
    }
};
