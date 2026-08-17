class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int sum=0;
        int res=0;
        mp[0]=-1;
        for(int i=0;i<n;i++){
               if(nums[i]==0){
                sum--;
               }else sum++;
               
                if(mp.find(sum)!=mp.end()){
                    int a=mp[sum];
                    res=max(res,i-a);
                }
                else{
mp[sum]=i;
                }
                
        }return res;
    }
};