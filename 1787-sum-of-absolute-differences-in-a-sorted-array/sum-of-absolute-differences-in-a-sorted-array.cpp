class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefix(n,0),suffix(n,0);
        prefix[0]=nums[0];
        suffix[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]+nums[i];
        }
        vector<int>res(n,0);
        res[0]=suffix[1]-(n-1)*nums[0];
        res[n-1]=((n-1)*nums[n-1])-prefix[n-2];
        for(int i=1;i<n-1;i++){
            res[i]=(suffix[i+1]-((n-i-1)*nums[i]))+((i*nums[i])-prefix[i-1]);
        }return res;
    }
};