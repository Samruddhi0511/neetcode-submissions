class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=INT_MAX;
        int maxProfit=0;
        for(int price:prices){
            if(price<minPrice){
                minPrice=price;
            }
            else{
                int temp=price-minPrice;
                maxProfit=max(temp, maxProfit);
            }
            
        }
        return maxProfit;
    }
};
