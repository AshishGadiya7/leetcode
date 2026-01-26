class Solution {
public:
    int hIndex(vector<int>& citations) {
         sort(citations.begin(),citations.end());
         reverse(citations.begin(),citations.end());
         int n=citations.size();
         int low=0,high=n-1,mid;
         
         while(low<=high){
            mid=(low+high)/2;
            if(citations[mid]>=mid+1){
                
                low=mid+1;
            }else high=mid-1;
         }return low;
    }
};