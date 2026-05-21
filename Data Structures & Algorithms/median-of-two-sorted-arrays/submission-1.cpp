class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()){
            swap(nums1, nums2);
        }
        int n1=nums1.size();
        int n2=nums2.size();

        int total=n1+n2;
        int half=total/2;
        int l=0; int h=n1;

        while(l<=h){
            int x=(l+h)/2;
            int y=(half-x);
            int nums1L=x>0? nums1[x-1] : INT_MIN;
            int nums1R=x<n1 ? nums1[x] : INT_MAX;
            int nums2L=y>0 ? nums2[y-1]:INT_MIN;
            int nums2R=y<n2 ? nums2[y]:INT_MAX;

            if(nums1L<=nums2R && nums2L<=nums1R){
                if(total%2==1) return min(nums1R, nums2R);
                else return (max(nums1L, nums2L) + min(nums1R, nums2R))/2.0;
            }
            else if(nums1L>nums2R){
                h=x-1;
            }
            else{
                l=x+1;
            }
        }
        return -1;

    }
};
