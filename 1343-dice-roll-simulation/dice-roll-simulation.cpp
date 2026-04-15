class Solution {
public:
int MOD=1e9+7;
int compute(vector<int>&rollMax,int n,int m,int cnt,vector<vector<vector<int>>>&dp){
    if(n==0)return 1;
    if(dp[n][m][cnt]!=-1)return dp[n][m][cnt];
    int ans=0;
     for(int i=0;i<6;i++){
        if(i==m){
            if(cnt<rollMax[i]){
                ans=(ans+compute(rollMax,n-1,m,cnt+1,dp))%MOD;
            }
        }else{
            ans=(ans+compute(rollMax,n-1,i,1,dp))%MOD;
        }
     }return dp[n][m][cnt]=ans;
}
    int dieSimulator(int n, vector<int>& rollMax) {
                   vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(6,vector<int>(16,-1)));
                     return compute(rollMax,n,0,0,dp);
    }
};