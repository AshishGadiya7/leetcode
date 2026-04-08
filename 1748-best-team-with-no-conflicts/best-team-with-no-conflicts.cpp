class Solution {
public:
int compute(vector<pair<int,int>>&v,int i,int score,vector<vector<int>>&dp){
    if(i==v.size())return 0;
    if(score!=-1 && dp[i][score+1]!=-1)return dp[i][score+1];
    int take=0,nottake;
    if(score==-1||v[i].second>=v[score].second){
        take=v[i].second+compute(v,i+1,i,dp);
    }nottake=compute(v,i+1,score,dp);
    return dp[i][score+1]=max(take,nottake);
}
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>>v;
        int maxscore=*max_element(scores.begin(),scores.end());
        vector<vector<int>>dp(scores.size(),vector<int>(scores.size()+1,-1));
        for(int i=0;i<scores.size();i++){
            v.push_back({ages[i],scores[i]});
        }
        sort(v.begin(),v.end());
        return compute(v,0,-1,dp);
    }
};