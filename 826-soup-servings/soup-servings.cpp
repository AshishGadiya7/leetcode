class Solution {
public:
double compute(int a,int b,vector<vector<double>>&dp){
     if(a<=0 && b>0)return 1.0;
     if(a<=0 && b<=0)return 0.5;
     if(b<=0)return 0;
     if(dp[a][b]!=-1)return dp[a][b];
     double temp1=compute(a-100,b,dp);
     double temp2=compute(a-75,b-25,dp);
     double temp3=compute(a-50,b-50,dp);
     double temp4=compute(a-25,b-75,dp);
     double res=temp1+temp2+temp3+temp4;
     return dp[a][b]=0.25*res;
}
    double soupServings(int n) {
        if(n >= 5000) return 1.0;
        vector<vector<double>>dp(n+1,vector<double>(n+1,-1));
        return compute(n,n,dp);
    }
};