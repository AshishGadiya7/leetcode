class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        
        int res=0;
        for(int i=1;i<n-1;i++){
              if(arr[i]>arr[i-1] && arr[i]>arr[i+1] && arr[res]<arr[i]){
                res=i;
              }
        }
        if(arr[0]>arr[res])res=0;
        if(arr[n-1]>arr[res])res=0;
        return res;
    }
};