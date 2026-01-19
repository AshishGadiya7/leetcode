class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int profit=0,minn=-1;
        for(int i=0;i<prices.size();i++){
            if(minn==-1){
                minn=prices[i];
            }else{
                profit=max(profit,prices[i]-minn);
                minn=min(minn,prices[i]);
            }
        }
        if(profit<0)return 0;
        return profit;
    }
};