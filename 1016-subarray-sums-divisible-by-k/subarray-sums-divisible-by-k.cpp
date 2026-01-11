class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        mp[0]=1;
        int sum=0,res=0;
        for(int i=0;i<n;i++){
               sum+=nums[i];
               int val=sum%k;
               if(val<0)val+=k;
               if(mp.find(val)!=mp.end()){
                       res+=mp[val];
                       mp[val]++;
               }else{
                mp[val]=1;
               }
        }return res;
    }
};