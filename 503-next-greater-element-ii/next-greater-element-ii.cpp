class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>s;
        int n=nums.size();
        vector<int>res(n,0);
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums[s.top()]<=nums[i]){
                s.pop();
            }
            if(s.empty()){
                res[i]=-1;
                s.push(i);
            }else{
                res[i]=nums[s.top()];
                s.push(i);
            }
        }
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums[s.top()]<=nums[i]){
                s.pop();
            }
            if(s.empty()){
                res[i]=-1;
                s.push(i);
            }else{
                res[i]=nums[s.top()];
                s.push(i);
            }
        }return res;
    }
};