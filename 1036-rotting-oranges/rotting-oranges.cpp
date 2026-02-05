class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 if(grid[i][j]==2){
                    q.push({i,j});
                 }
            }
        }
        int res=0;
        while(!q.empty()){
            int s=q.size();
            bool changed=false;
            for(int k=0;k<s;k++){
                 pair<int,int>temp=q.front();
                 int i=temp.first;
                 int j=temp.second;
                 q.pop();
                 if(i+1<n && grid[i+1][j]==1){
                    grid[i+1][j]=2;
                    q.push({i+1,j});
                    changed=true;
                 }if(j+1<m && grid[i][j+1]==1){
                    grid[i][j+1]=2;
                    q.push({i,j+1});
                    changed=true;
                 }if(i-1>=0 && grid[i-1][j]==1){
                    grid[i-1][j]=2;
                    q.push({i-1,j});
                    changed=true;
                 }if(j-1>=0 && grid[i][j-1]==1){
                    grid[i][j-1]=2;
                    q.push({i,j-1});
                    changed=true;
                 }
            }
            if(changed)res++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)return -1;
            }
        }
        return res;
    }
};