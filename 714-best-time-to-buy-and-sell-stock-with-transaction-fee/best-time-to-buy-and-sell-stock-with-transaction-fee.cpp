class Solution {
public:
int compute(vector<int>&p,int i,int temp,int fee,vector<vector<int>>&dp){
    if(i==p.size())return 0;
    if(dp[i][temp]!=-1)return dp[i][temp];
    int a=0,b=0;
    int sell,notsell;
    if(temp){
        a=-p[i]+compute(p,i+1,0,fee,dp);
        b=compute(p,i+1,temp,fee,dp);
        return dp[i][temp]=max(a,b);
    }else{
        
        sell=p[i]-fee+compute(p,i+1,1,fee,dp);
        notsell=compute(p,i+1,temp,fee,dp);
    }
    return dp[i][temp]= max(a,max(sell,notsell));
}
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
         return compute(prices,0,1,fee,dp);
    }
};