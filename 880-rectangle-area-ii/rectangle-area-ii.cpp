class Solution {
public:
#define MOD 1000000007
    int rectangleArea(vector<vector<int>>& rectangles) {
        set<int>x,y;
        int n=rectangles.size();
        for(int i=0;i<n;i++){
            x.insert(rectangles[i][0]);
            x.insert(rectangles[i][2]);
            y.insert(rectangles[i][1]);
            y.insert(rectangles[i][3]);
        }
        int idx=0;
        unordered_map<int,int>x_map,y_map;
        for(auto i:x){
            x_map[i]=idx;
            idx++;
        }
        idx=0;
        for(auto i:y){
            y_map[i]=idx;
            idx++;
        }
        long long  ans=0;
        vector<int>x_cor(x.begin(),x.end());
        vector<int>y_cor(y.begin(),y.end());
        vector<vector<bool>>visited(x.size(),vector<bool>(y.size(),false));
        for(int i=0;i<n;i++){
            for(int j=x_map[rectangles[i][0]];j<x_map[rectangles[i][2]];j++){
                for(int k=y_map[rectangles[i][1]];k<y_map[rectangles[i][3]];k++){
                    if(!visited[j][k]){
                        long long len=x_cor[j+1]-x_cor[j];
                        long long bre=y_cor[k+1]-y_cor[k];
                        ans=(ans+(len*bre)%MOD)%MOD;
                        visited[j][k]=true;
                    }
                }
            }
        }return ans;

    }
};