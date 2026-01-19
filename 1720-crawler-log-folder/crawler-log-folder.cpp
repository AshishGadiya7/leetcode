class Solution {
public:
    int minOperations(vector<string>& logs) {
        int res=0;
        stack<int>s;
        for(int i=0;i<logs.size();i++){
            if(logs[i]=="../"){
                if(!s.empty())s.pop();
            }
            else if(logs[i]=="./")continue;
            else{
                s.push(i);
            }
        }return s.size();
    }
};