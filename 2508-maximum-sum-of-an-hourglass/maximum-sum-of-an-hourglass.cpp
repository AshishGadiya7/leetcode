class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int m,n;
        m=grid.size(),n=grid[0].size();
        vector<vector<int>>prefix(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            prefix[i][0]=grid[i][0];
        }
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                prefix[i][j]=prefix[i][j-1]+grid[i][j];
            }
        }
        int sum=0;
        for(int i=0;i<m-2;i++){
              for(int j=0;j<n;j++){
                if(j==2){
                    int temp=prefix[i][j]+prefix[i+1][j-1]-prefix[i+1][j-2]+prefix[i+2][j];
                    sum=max(sum,temp);
                }
                if(j>2){
                    int temp=prefix[i][j]-prefix[i][j-3]+prefix[i+1][j-1]-prefix[i+1][j-2]+prefix[i+2][j]-prefix[i+2][j-3];
                    sum=max(sum,temp);
                }
              }
        }return sum;
    }
};