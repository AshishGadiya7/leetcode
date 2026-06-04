class Solution {
public:
void compute(int n,int k,int j,vector<int>&temp,vector<vector<int>>&res){
    if(temp.size()==k){
        res.push_back(temp);
        return;
    }
         for(int i=j;i<=n;i++){
              temp.push_back(i);
              compute(n,k,i+1,temp,res);
              temp.pop_back();
         }
}
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        vector<vector<int>>res;
        compute(n,k,1,temp,res);
        return res;
    }
};