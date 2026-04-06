class Solution {
public:
double compute(int n,int k,int row,int col,vector<vector<vector<double>>>& dp){
    
    if(row<n && row>=0 && col<n && col>=0 ){
        if(dp[k][row][col] !=-1)return dp[k][row][col];
        if(k==0)return 1;
        else {
               return dp[k][row][col]= (compute(n,k-1,row-1,col-2,dp)+compute(n,k-1,row-2,col-1,dp)+compute(n,k-1,row-2,col+1,dp)+compute(n,k-1,row-1,col+2,dp)+compute(n,k-1,row+1,col+2,dp)+compute(n,k-1,row+2,col+1,dp)+compute(n,k-1,row+2,col-1,dp)+compute(n,k-1,row+1,col-2,dp))/8.0;
        }
    }return 0;
     
}
    double knightProbability(int n, int k, int row, int column) {
          vector<vector<vector<double>>> dp(k+1, vector<vector<double>>(n, vector<double>(n, -1)));
         return compute(n,k,row,column,dp);
    }
};