class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>>temp(m,vector<int>(n,INT_MIN));
        temp[0][0]=health-grid[0][0];

        if(temp[0][0]<1) return false;

        queue<pair<int,int>>q;
        q.push({0,0});

        while(!q.empty()){
            auto a=q.front();
            q.pop();

            int i=a.first;
            int j=a.second;

            if(i-1>=0){
                if(temp[i-1][j] < temp[i][j]-grid[i-1][j]){
                    temp[i-1][j]=temp[i][j]-grid[i-1][j];
                    if(temp[i-1][j]>=1)
                        q.push({i-1,j});
                }
            }

            if(i+1<m){
                if(temp[i+1][j] < temp[i][j]-grid[i+1][j]){
                    temp[i+1][j]=temp[i][j]-grid[i+1][j];
                    if(temp[i+1][j]>=1)
                        q.push({i+1,j});
                }
            }

            if(j-1>=0){
                if(temp[i][j-1] < temp[i][j]-grid[i][j-1]){
                    temp[i][j-1]=temp[i][j]-grid[i][j-1];
                    if(temp[i][j-1]>=1)
                        q.push({i,j-1});
                }
            }

            if(j+1<n){
                if(temp[i][j+1] < temp[i][j]-grid[i][j+1]){
                    temp[i][j+1]=temp[i][j]-grid[i][j+1];
                    if(temp[i][j+1]>=1)
                        q.push({i,j+1});
                }
            }
        }

        if(temp[m-1][n-1]>=1)return true;

        return false;
    }
};