class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int res=nums[0]+nums[1]+nums[2];
        int num=nums.size()-1;
        int i=num;
        while(i>=0){
            
            int low=0;
            int high=i-1;
            while(low<high){
                int sum=nums[low]+nums[high]+nums[i];
                if(sum==target){
                    return sum;
                }
                if(abs(sum-target)<abs(res-target)){
                    res=sum;
                }
                if(sum>target){
                    high--;
                }else{
                    low++;
                }
                
            }i--;
        }return res;
    }
};