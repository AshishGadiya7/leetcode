class Solution {
public:
int compute(vector<int>&v,int i,int target,vector<vector<int>>&dp){
    if(i==v.size()){
        if(target==0)return 1;
        return 0;
    }
    if(target==0)return 1;
    if(dp[i][target]!=-1)return dp[i][target];
    int take=0,nottake;
    if(v[i]<=target){
        take=compute(v,0,target-v[i],dp);
    }
    nottake=compute(v,i+1,target,dp);
    return dp[i][target]= take+nottake;
}
    int combinationSum4(vector<int>& nums, int target) {
        vector<vector<int>>dp(nums.size(),vector<int>(target+1,-1));
         return compute(nums,0,target,dp);
    }
};