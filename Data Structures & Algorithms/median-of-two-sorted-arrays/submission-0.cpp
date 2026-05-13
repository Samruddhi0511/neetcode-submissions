class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //always keep nums1 smaller
        if(nums1.size()>nums2.size()){
            swap(nums1,nums2);
        }
        int m=nums1.size();
        int n=nums2.size();
        int low=0;
        int high=m;

        while(low<=high){
            int partitionX=(low+high)/2;
            int partitionY=(m+n+1)/2 - partitionX;
            //these partitions basically tell how mnay elements are there on the left side of the median

            //edge case
            int maxLX=(partitionX==0)?(INT_MIN):nums1[partitionX-1];
            int minRX=(partitionX==m)?(INT_MAX):nums1[partitionX];

            int maxLY=(partitionY==0)?(INT_MIN):nums2[partitionY-1];
            int minRY=(partitionY==n)?(INT_MAX):nums2[partitionY];

            //main condition
            if(maxLX<=minRY && maxLY <= minRX){
                //its a valid solution
                if((m+n)%2==0){
                    
                    return (max(maxLX, maxLY)+min(minRX, minRY))/2.0;
                }
                else{
                    return max(maxLX, maxLY);
                }
            }
            else if(maxLX>minRY){
                //v need to reduce the value of X
                high=partitionX-1;
            }
            else{
                //means that maxLY > minRX reduce maxLY ie move partition x to right
                low=partitionX+1;
            }

        }
        return 0.0;
    }
};
