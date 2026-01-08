class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>res(n,0);
        for(int i=0;i<bookings.size();i++){
            res[bookings[i][1]-1]+=bookings[i][2];
            if(bookings[i][0]-1>0)res[bookings[i][0]-2]-=bookings[i][2];
        }
        for(int i=n-2;i>=0;i--){
            res[i]=res[i]+res[i+1];
        }return res;
    }
};