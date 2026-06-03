class Solution {
public:
void compute(vector<int>&nums,vector<int>&visited,vector<int>&temp,vector<vector<int>>&res){
    if(temp.size()==nums.size() && find(res.begin(),res.end(),temp)==res.end()){
            res.push_back(temp);
            return;
    }
    for(int i=0;i<nums.size();i++){
            if(visited[i]){
                    continue;
            }
            else{
                temp.push_back(nums[i]);
                visited[i]=1;
                compute(nums,visited,temp,res);
                visited[i]=0;
                temp.pop_back();
            }
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        vector<int>visited(n,0);
        vector<vector<int>>res;
        vector<int>temp;
        compute(nums,visited,temp,res);
        return res;
    }
};