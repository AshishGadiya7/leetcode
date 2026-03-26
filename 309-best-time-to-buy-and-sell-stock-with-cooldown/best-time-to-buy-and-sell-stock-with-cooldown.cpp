class Solution {
public:
int compute(vector<int>&prices,int i,int buy,vector<vector<int>>&dp){
    if(i>=prices.size())return 0;
    int sell,notsell;
    if(dp[i][buy]!=-1)return dp[i][buy];
    if(buy){
        int a=-prices[i]+compute(prices,i+1,0,dp);
        int b=compute(prices,i+1,buy,dp);
        return dp[i][buy]=max(a,b);
    }else{
        sell=prices[i]+compute(prices,i+2,1,dp);
        notsell=compute(prices,i+1,buy,dp);
    }return dp[i][buy]= max(sell,notsell);
}
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return compute(prices,0,1,dp);
    }
};