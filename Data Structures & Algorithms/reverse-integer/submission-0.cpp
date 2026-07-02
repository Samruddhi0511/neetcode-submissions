class Solution {
public:
    int reverse(int x) {
        int res=0;
        while(x){
            int rem=x%10;
            x=x/10;
            if (res > 214748364 || (res == 214748364 && rem > 7)) return 0;
            
            // Check for Min Overflow (-2147483648)
            if (res < -214748364 || (res == -214748364 && rem < -8)) return 0;
            res= res*10 + rem;
        }

        return res;
    }
};
