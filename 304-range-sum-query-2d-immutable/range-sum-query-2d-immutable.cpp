class NumMatrix {
public:
vector<vector<int>>v;
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                matrix[i][j]+=matrix[i][j-1];
            }
        }
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                matrix[j][i]+=matrix[j-1][i];
            }
        }
        v=matrix;
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int up=0,left=0,common=0;
        if(row1-1>=0)up=v[row1-1][col2];
        if(col1-1>=0)left=v[row2][col1-1];
        if(row1-1>=0 && col1-1>=0)common=v[row1-1][col1-1];
        return v[row2][col2]-up-left+common;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */