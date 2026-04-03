class Solution {
public:
int mod = 1e9 + 7;
int compute(int n,int k,int target,vector<vector<int>>&dp){
    if(n==0){
        if(target==0)return 1;
        else return 0;
    }
    if(dp[n][target]!=-1)return dp[n][target];
    long long way=0;
    for(int i=1;i<=k;i++){
        if(target-i>=0){
            way=(way+compute(n-1,k,target-i,dp))%mod;
        }
    }return dp[n][target]= way;

}
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(31,vector<int>(1001,-1));
        return compute(n,k,target,dp);
    }
};