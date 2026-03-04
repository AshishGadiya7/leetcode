class Solution {
public:
    int scoreOfParentheses(string s) {
        int n=s.size();
        stack<int>sta;
        sta.push(0);
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                sta.push(0);
            }else{
                int res;
                 int a=sta.top();
                 sta.pop();
                 res=max(1,2*a);
                 sta.top()+=res;
            }
        }return sta.top();
    }
};