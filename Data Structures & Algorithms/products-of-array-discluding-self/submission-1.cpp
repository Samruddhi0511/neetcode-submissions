class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        if (n == 0) return {};
        vector<int> prefix(n,1);
        vector<int> suffix(n,1);
        int product1=1;
        int product2=1;
        for(int i=1;i<n;i++){
            product1=product1*nums[i-1];
            prefix[i]=product1;
        }
        for(int j=n-2;j>=0;j--){
            product2=product2*nums[j+1];
            suffix[j]=product2;
        }

        vector<int> output(n);
        for(int k=0;k<n;k++){
            output[k]=(prefix[k]*suffix[k]);
        }
        return output;

    }
};
