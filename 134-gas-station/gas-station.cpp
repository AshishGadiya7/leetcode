class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalgas=0,totalcost=0;
        int n=gas.size();
        for(int i=0;i<n;i++){
            totalgas+=gas[i];
            totalcost+=cost[i];
        }
        if(totalcost>totalgas)return -1;
        int res=0,currentcost=0;
        for(int i=0;i<n;i++){
                currentcost+=(gas[i]-cost[i]);
                if(currentcost<0){
                    currentcost=0;
                    res=i+1;
                }
        }return res;
    }
};