class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>s;
        int n=nums1.size(),m=nums2.size();
        vector<int>res(n,-1);
        vector<int>temp(m,0);
        for(int i=m-1;i>=0;i--){
             while(!s.empty() && nums2[s.top()]<=nums2[i]){
                s.pop();
             }
             if(s.empty()){
                 s.push(i);
                 temp[i]=-1;
             }else{
                 temp[i]=nums2[s.top()];
                 s.push(i);
             }
        }
        for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
                  if(nums1[i]==nums2[j]){
                      res[i]=temp[j];
                  }
             }
        }return res;
    }
};