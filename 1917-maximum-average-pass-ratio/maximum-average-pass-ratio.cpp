class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<vector<double>>q;
        int n=classes.size();
        for(int i=0;i<n;i++){
               double total=classes[i][1];
               double pass=classes[i][0];
               double ratio=((pass+1)/(total+1))-(pass/total);
               q.push({ratio,pass,total});
               
        }
        int stu=extraStudents;
        while(stu!=0){
            vector<double>temp;
            temp=q.top();
            q.pop();
            double totals=temp[2]+1;
            double pass=temp[1]+1;
            temp[0]=((pass+1)/(totals+1))-(pass/totals);
            temp[1]=pass,temp[2]=totals;
            q.push(temp);
            stu--;
        }
        double res=0.0;
        while(!q.empty()){
            vector<double>temp=q.top();
            q.pop();
            res+=temp[1]/(double)temp[2];
        }return res/(n);
    }
};