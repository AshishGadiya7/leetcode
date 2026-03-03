class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>sta;
        int n=s.size();
        for(int i=0;i<n;i++){
             if(sta.empty()){
                sta.push(s[i]);
             }else if(sta.top()=='(' && s[i]==')'){
                sta.pop();
             }else{
                sta.push(s[i]);
             }
        }return sta.size();
    }
};