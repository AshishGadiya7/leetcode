class Solution {
public:
int gcd(int a,int b){
    int ans=1;
    for(int i=1;i<=a && i<=b;i++){
        if(a%i==0 && b%i==0)ans=i;
    }return ans;
}
    int findGCD(vector<int>& nums) {
        int a=nums[0],b=nums[0];
        int n=nums.size();
        for(int i=0;i<n;i++){
               if(nums[i]>a){
                a=nums[i];
               }
               if(nums[i]<b)b=nums[i];
        }
        return gcd(a,b);
    }
};