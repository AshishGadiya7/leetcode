class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                   if(i%2==0){
                         int temp=(j+k)%m;
                         if(mat[i][temp]!=mat[i][j])return false;
                   }else{
                              int temp = (j - k % m + m) % m;
                              if(mat[i][temp]!=mat[i][j])return false;
                   }
            }
        }return true;
    }
};