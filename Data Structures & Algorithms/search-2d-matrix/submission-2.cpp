class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0;
        int m=matrix.size();
        int n=matrix[0].size();
        int r=(m*n)-1;
        while(l<=r){
            int mid=(l+r)/2;
            int row=mid/n;
            int col=mid%n;
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]>target) r=mid-1;
            else l=mid+1;
        }
        return false;
    }
};
