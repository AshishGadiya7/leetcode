class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int window=0,left=0,ans=n+1;
        for(int i=0;i<n;i++){
            window=window+nums[i];
            while(window>=target){
              ans=min(ans,i-left+1);
              window=window-nums[left++];
            }
        }if(ans==n+1){
            return 0;
        }return ans;
    }
};