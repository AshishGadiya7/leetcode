class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
             nums[i]=abs(nums[i]);
        }
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        long long res=0;
        int i=0,j=n-1;
        while(i<j){
            int a=(nums[i]*nums[i]);
            int b=(nums[j]*nums[j]);
            res=res+a-b;
            i++,j--;
        }
        int a=(nums[i]*nums[i]);
        if(i==j)res=res+a;
        return res;

    }
};