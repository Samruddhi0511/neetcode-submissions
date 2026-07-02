class Solution {
public:
    double myPow(double x, int N) {
        long long n=N;
        if(n<0){
            x=1/x;
            n=-n;
        }

        double result=1.0;
        double curr=x;
        while(n>0){
            if(n%2==1){
                result*=curr;
            }
            
            curr=curr*curr;
            
            n=n/2;
        }
        return result;
    }
};
