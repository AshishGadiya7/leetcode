class MyCalendarThree {
public:
map<int,int>mp;
int res=0;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        mp[startTime]++;
        mp[endTime]--;
        int temp=0,maxval=INT_MIN;
        for(auto it:mp){
            temp=temp+it.second;
            maxval=max(maxval,(temp));
            
        }if(maxval>res)res=maxval;
        return res;

    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */