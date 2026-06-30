class Solution {
public:
    int calculate(int n){
        int sum=0;
        while(n){
            int remainder=n%10;
            n=n/10;
            sum=sum + (remainder*remainder);
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> seen;
        while(n!=1 && seen.find(n)==seen.end()){
            
            seen.insert(n);
            n=calculate(n);
        }
        return n==1;
    }
};
