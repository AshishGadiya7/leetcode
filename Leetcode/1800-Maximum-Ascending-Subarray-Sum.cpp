class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum=0;
        int subsum=nums[0];
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                subsum=subsum+nums[i+1];
            }else{
            sum=max(subsum,sum);
            subsum=nums[i+1];}
        }
        sum=max(subsum,sum);
        return sum;
    }
};