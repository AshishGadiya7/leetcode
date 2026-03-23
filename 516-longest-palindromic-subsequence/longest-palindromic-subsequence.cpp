class Solution {
public:
int findsubsequence(string &s,string &a,int n,int m,vector<vector<int>>&dp){
    if(n<0 || m<0)return 0;
    if(dp[n][m]!=-1)return dp[n][m];
        if(s[n]==a[m]){
        return dp[n][m]= 1+findsubsequence(s,a,n-1,m-1,dp);
    }
    return dp[n][m]=max(findsubsequence(s,a,n-1,m,dp),findsubsequence(s,a,n,m-1,dp));
}
    int longestPalindromeSubseq(string s) {
        string a=s;
         reverse(a.begin(),a.end());
         int n=s.size();
         vector<vector<int>>dp(n,vector<int>(n,-1));
         return findsubsequence(s,a,s.size()-1,a.size()-1,dp);
         
    }
};