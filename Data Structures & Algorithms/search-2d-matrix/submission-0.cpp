class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int low=0;
        int high=m*n - 1;

        while(low<=high){
            int middle=low+((high-low)/2);
            int row=middle/n;
            int col=middle%n;
            if(target==matrix[row][col]){
                return true;
            }
            else if(target>matrix[row][col]){
                low=middle+1;
            }
            else{
                high=middle-1;
            }
        }
        return false;
    }
};
