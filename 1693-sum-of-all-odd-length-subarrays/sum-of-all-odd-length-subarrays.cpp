class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n=arr.size();
        vector<int>prefix(n);
        prefix[0]=arr[0];
        for(int i=1;i<n;i++){
            prefix[i]=arr[i]+prefix[i-1];
        }
        int res=0,count;
        for(int i=0;i<n;i++){
            count=2;
            for(int j=i+1;j<n;j++){
                 if(count%2!=0){
                    if(i==0)res+=prefix[j];
                    else
                    res+=(prefix[j]-prefix[i-1]);
                 }count++;
            }
        }return res+prefix[n-1];
    }
};