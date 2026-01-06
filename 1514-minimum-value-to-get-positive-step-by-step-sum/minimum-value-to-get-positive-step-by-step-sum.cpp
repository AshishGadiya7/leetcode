class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        int temp=1;
        for(int i=0;i<n;i++){
               if(prefix[i]<temp){
                temp=prefix[i];
               }
        }
        if(temp==1)return 1;
        return abs(temp)+1;
    }
};