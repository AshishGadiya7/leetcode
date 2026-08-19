class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>arr=prices;
        int n=prices.size();
        
        vector<int>right(n,0);
        right[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
                if(arr[i]>right[i+1]){
                    right[i]=arr[i];
                }else{
                    right[i]=right[i+1];
                }
        }
        int res=0;
        int maxele=0;
        for(int i=0;i<n;i++){
            if(right[i]-arr[i]>maxele){
                maxele=(right[i]-arr[i]);
                res=i;
            }
        }return maxele;
    }
};