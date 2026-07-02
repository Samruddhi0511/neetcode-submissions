class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";

        int m=num1.size(); int n=num2.size();
        vector<int> res(m+n, 0);
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                int n1=num1[i]-'0';
                int n2=num2[j]-'0';

                int prod=n1*n2;
                int sum=prod+res[i+j+1];
                res[i+j+1]=sum%10;
                res[i+j]+=sum/10;
            }
        }
        string ans="";
        for(int num : res){
            if(!(ans.empty() && num==0)){
                ans.push_back(num + '0');
            }
        }
        return ans;
    }
};
