class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        // if(arr[0]==1 && arr[n-1]==n){
        //     return arr[n-1];
        // }
        arr[0]=1;
        // vector<int>temp(n,0);
        // temp[0]=1;
        // for(int i=1;i<n;i++){
        //     temp[i]=arr[i]-arr[i-1];
        // }
        for(int i=1;i<n;i++){
            if(arr[i]-arr[i-1]>1){
                arr[i]=arr[i-1]+1;
            }
        }return arr[n-1];
    }
};