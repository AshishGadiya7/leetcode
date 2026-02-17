class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 1;
        vector<int>temp(n-1,0);
        for(int i=1;i<n;i++){
                if(nums[i]>nums[i-1]){
                    temp[i-1]=1;
                } else if(nums[i]<nums[i-1]){
                    temp[i-1]=-1;
                } 
        }
        int count=0;
        int start=0,pre;
        while(start<temp.size() && temp[start]==0)start++;
        if(start<temp.size()){
            count++;
            pre=temp[start];
            start++;
        }else{
            return 1;
        }
        while(start<temp.size()){
                if(temp[start]<0 && pre>0){
                    count++;
                    pre=temp[start];
                }else if(temp[start]>0 && pre<0){
                    count++;
                    pre=temp[start];
                }
                start++;
        }return count+1;
    }
};